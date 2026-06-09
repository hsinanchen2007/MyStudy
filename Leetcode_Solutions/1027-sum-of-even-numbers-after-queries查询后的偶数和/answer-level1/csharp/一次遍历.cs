根据改变前的奇偶数决定新的求和
```
 public int[] SumEvenAfterQueries(int[] A, int[][] queries) {
        int qh=queries.Length;
        var res=new List<int>();
        int sum=0;
        foreach(var num in A){
            if(num%2==0){
                sum+=num;
            }
        }
        for(var i=0;i<qh;i++){
            var val=queries[i][0];
            var index=queries[i][1];
            var t=A[index]+val;
            if(A[index]%2==0){
                sum=sum-A[index];
                if(t%2==0){
                    sum+=t;
                }
            }else if(t%2==0){
                sum+=t;
            }
            A[index]=t;
            res.Add(sum);
        }
        return res.ToArray();
    }
```
