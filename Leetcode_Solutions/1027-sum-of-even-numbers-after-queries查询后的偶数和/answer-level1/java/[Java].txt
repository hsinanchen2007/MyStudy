```
/*
      A[index]   queries[i] [0]    相加后的（奇偶）
    1>偶                奇      :       奇
    2>偶                偶      :       偶
    3>奇                偶      :       奇
    4>奇                奇      :       偶
    */
    public int[] sumEvenAfterQueries(int[] A, int[][] queries) {
        int sumEven = 0;
        int[] ans = new int[queries.length];
        for(int n : A){
            if(n % 2 == 0)
                sumEven += n;
        }
        for(int i = 0; i < queries.length; i++){
            int val = queries[i][0];
            int index = queries[i][1];
            if(A[index] % 2 == 0 && val % 2!= 0){
                //1>
                sumEven -= A[index];
            }else if(A[index] % 2 == 0 && val % 2== 0){
                //2>
                sumEven += val;
            }else if(A[index] % 2 != 0 && val % 2 != 0){
                //4>
                sumEven += A[index] + val;
            }
            //3>不用修改sumEven
            A[index] += val;
            ans[i] = sumEven;
        }
        return ans;
    }
```

