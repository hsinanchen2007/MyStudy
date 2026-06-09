```
    public int minSwap(int[] A, int[] B) {
        int[] keep = new int[A.length];//不变
        int[] swap = new int[A.length];//交换
        Arrays.fill(keep, Integer.MAX_VALUE);
        Arrays.fill(swap, Integer.MAX_VALUE);
        keep[0] = 0;// 就一位 交换一下 为0
        swap[0] = 1;// 就一位 交换一下 为1
        for (int i = 1; i < A.length; i++) {
            //没交换
            if (A[i] > A[i - 1] && B[i] > B[i - 1]) {
                keep[i] = keep[i - 1];
                swap[i] = swap[i - 1] + 1;//i - 1交换了  i也交换了  相当于负负得正
            }
            //交换了
            if (A[i] > B[i - 1] && B[i] > A[i - 1]) {
                keep[i] = Math.min(keep[i], swap[i - 1]);//前一位i - 1交换了  i不懂
                swap[i] = Math.min(swap[i], keep[i - 1] + 1);//i - 1不交换  i交换  
            }
        }
        return Math.min(keep[A.length - 1], swap[A.length - 1]);
    }
```
