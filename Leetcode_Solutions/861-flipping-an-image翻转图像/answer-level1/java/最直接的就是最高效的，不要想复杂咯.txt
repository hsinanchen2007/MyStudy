![image.png](https://pic.leetcode-cn.com/262ebce5d9780712be7c5c6bfd0802fb78a9375f751594109296fde3b462e03b-image.png)

public int[][] flipAndInvertImage(int[][] A) {
        for (int i = 0; i < A.length; i++) {
            int[] B = A[i];
            int[] C = new int[B.length];
            for (int j = B.length-1,k=0; j >= 0; j--,k++) {
                int D = B[j];
                if (D==1) D = 0;
                else D = 1;
                C[k] = D;
            }
            A[i] = C;
        }
        return A;
    }