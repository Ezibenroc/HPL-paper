#define |\color{colorfuncall}HPL\_dgemm|(layout, TransA, TransB, M, N, K,     \
        alpha, A, lda, B, ldb, beta, C, ldc) ({        \
    double size = ((double)M)*((double)N)*((double)K); \
    double expected_time = 1.029e-11*size + 1.981e-12; \
    |\color{colorfuncall}smpi\_execute\_benched|(expected_time);               \
})
