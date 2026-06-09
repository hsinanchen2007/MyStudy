```
    public boolean splitArraySameAverage(int[] A) {
        int sum = 0;
        for (int num : A) {
            sum += num;
        }
        //Asum / len = Bsum / i = Csum / len - i
        int len = A.length; 
        Arrays.sort(A);
        for (int i = 1; i <= len / 2; i++) {
            if (sum * i % len == 0) {
                //是否存在长度为i 的 sum和为 sum * i / len  B arr
                if (dfs(A, i, sum * i / len, 0)){
                    return true;
                }
            }
        }
        return false;
    }
    private boolean dfs(int[] A, int n, int targetSum, int startIndex) {
        if (targetSum == 0 && n == 0) {
            return true;
        }
        if (n != 0) {
            for (int i = startIndex; i < A.length; i++) {
                if (i > startIndex && A[i] == A[i - 1]) {
                    continue;
                }
                if (dfs(A, n - 1, targetSum - A[i], i + 1)) {
                    return true;
                }
            }
        }
        return false;
    }
```
