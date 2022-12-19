int fib(int N){
    if (N <= 1) {
        return N;
    }

    int N_1_value = 0;
    int N_2_value = 1;
    int i, N_value;

    for (i = 2; i <= N; i++) {
        N_value = N_1_value + N_2_value;
        N_1_value = N_2_value;
        N_2_value = N_value;
    }

    return N_value;
}