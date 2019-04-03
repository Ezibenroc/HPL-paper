#define |\color{colorfuncall}HPL\_dgemm|(layout, TransA, TransB,                       \
        M, N, K, alpha, A, lda, B, ldb, beta, C, ldc) ({        \
    double expected_time = (1.029e-11)*((double)M)*             \
                   ((double)N)*((double)K) + 1.981e-12;         \
    if(expected_time > 0)  |\color{colorfuncall}smpi\_execute\_benched|(expected_time); \
})
