```
 public int largestSumAfterKNegations(int[] A, int K) {
        //首先排序, 排序是为了保证反转负数永远是从最小开始反转
        Arrays.sort(A);
        //先把负数都反转
        for (int i = 0; i < A.length && K > 0; i++) {
            if (A[i] < 0) {
                A[i] = -A[i];
                K--;
            }
        }
        //K大于0说明还要反转正数,两次反转可以抵消,所以K要么是0,要么是1
        K = K % 2;
        
        //求出数组和,顺便求出最小值
        int sum = 0;
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < A.length; i++) {
            sum += A[i];
            if (A[i] < min)
                min = A[i];
        }

        //如果K是1的话,要反转最小值,那么数组合sum就要减去两倍的最小值
        if (K == 1) {
            sum -= 2 * min;
        }

        return sum;
    }

```