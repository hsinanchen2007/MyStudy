

int tribonacci(int n){
    int T[4] = {0, 1, 1, 2};
    for (int i = 3; i <= n; i++) {
        T[i % 4] = T[(i + 1) % 4] + T[(i + 2) % 4] + T[(i + 3) % 4];  
    }
    return T[n % 4];
}

