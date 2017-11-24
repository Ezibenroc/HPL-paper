#define |\color{colorfuncall}HPL\_dtrsm|(layout, Side, Uplo, TransA, Diag, M, N, alpha, A, lda, B, ldb) ({ \
    double expected_time;                                                           \
    double coefficient, intercept;                                                  \
    if((M) > 512 && (N) > 512) {                                                    \
        coefficient = (double)SMPI_DTRSM_PHI_COEFFICIENT;                           \
        intercept = (double)SMPI_DTRSM_PHI_INTERCEPT;                               \
    } else {                                                                        \
        coefficient = (double)SMPI_DTRSM_CPU_COEFFICIENT;                           \
        intercept = (double)SMPI_DTRSM_CPU_INTERCEPT;                               \
    }                                                                               \
    if((Side) == HplLeft) {                                                         \
        expected_time = coefficient*((double)(M))*((double)(M))*((double)(N));      \
    } else {                                                                        \
        expected_time = coefficient*((double)(M))*((double)(N))*((double)(N));      \
    }                                                                               \
    expected_time += intercept                                                      \
    if(expected_time > 0)                                                           \
        |\color{colorfuncall}smpi\_execute\_benched|(expected_time);                                        \
})
