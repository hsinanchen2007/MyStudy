递归时间久但不需要额外空间, 迭代时间少, 但需要额外空间
```
    /**
     * 迭代
     * @param N 位置
     * @return int
     */
    public int fib(int N) {
        int[] fib = new int[N + 2];
        fib[0] = 0;
        fib[1] = 1;
        if (N < 2) return fib[N];
        for (int i = 2; i <= N; i++) {
            fib[i] = fib[i-1] + fib[i-2];
        }
        return fib[N-1] + fib[N-2];
    }

    /**
     * 递归
     * @param N 位置
     * @return int
     */
    public int fib2(int N) {
        if (N == 1) return 1;
        if (N == 0) return 0;
        return fib(N - 1) + fib(N - 2);
    }
```