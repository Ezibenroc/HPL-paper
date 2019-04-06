NAME=paper
ARCHIVE=replicable
# ARCHIVE_FILES=$(shell git ls-tree -r master --name-only | grep -v -e '$(NAME).pdf')
ARCHIVE_FILES=$(NAME).org refs.bib Makefile figures/*

all: $(NAME).pdf

fast:
	emacs -batch -l ~/.emacs.d/init.el --eval "(setq enable-local-eval t)" --eval "(setq enable-local-variables t)" \
	--eval "(setq org-export-babel-evaluate t)" paper.org  --funcall org-latex-export-to-latex
	pdflatex paper.tex

watch:
	while inotifywait -e close_write paper.org; do make fast; done

# If you have good Emacs and Org-mode installed by default, delete "-l ~/.emacs.d/init.el"
%.tex: %.org
	emacs -batch -l ~/.emacs.d/init.el $^  --funcall org-babel-tangle
	emacs -batch -l ~/.emacs.d/init.el --eval "(setq enable-local-eval t)" --eval "(setq enable-local-variables t)" \
	--eval "(setq org-export-babel-evaluate t)" $^  --funcall org-latex-export-to-latex

%.pdf: %.tex
	pdflatex $^
	bibtex `basename $^ .tex`
	pdflatex $^
	pdflatex $^
	pdftops `basename $^ .tex`.pdf
	ps2pdf14 -dPDFSETTINGS=/prepress `basename $^ .tex`.ps



%.html: %.org
	emacs -batch -l ~/.emacs.d/init.el --eval "(setq enable-local-eval t)" --eval "(setq enable-local-variables t)" \
	   --eval "(setq org-export-babel-evaluate t)" $^  --funcall org-html-export-to-html

$(ARCHIVE).tgz: $(ARCHIVE_FILES)
	tar --xform "s|^|$(ARCHIVE)/|" -zcf $@ $^

clean:
	rm -f $(NAME).aux $(NAME).bbl $(NAME).blg $(NAME).log $(NAME).out *~

distclean: clean
	rm -f $(NAME).html $(NAME).tex $(NAME).pdf
