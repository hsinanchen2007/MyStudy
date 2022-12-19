```
    public int minIncrementForUnique(int[] A) {
        if (A.length==0)
            return 0;
        Arrays.sort(A);
        int num  = A[0];
        int count = 0;
        //从A[0]开始每个数都变成从A[0]开始的自然数
        for (int i=1;i<A.length;i++){
            if (A[i]==num){
                count++;
                num ++;
            }else if (A[i]>num){
                num = A[i];
            }else {
                num++;
                int result = num - A[i];
                count += result;
            }
        }
        return count;
    }
```
