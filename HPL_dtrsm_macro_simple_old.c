#define |\color{colorfuncall}HPL\_dtrsm|(layout, Side, Uplo, TransA, Diag, M, N, alpha, A, lda, B, ldb) ({      \
    double expected_time = (9.882e-12)*((double)M)*((double)M)*((double)N) + 4.329e-02;   \
    if(expected_time > 0)                                                                 \
        |\color{colorfuncall}smpi\_execute\_benched|(expected_time);                      \
})
