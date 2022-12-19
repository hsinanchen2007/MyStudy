```
class Solution {
    public int maxCount(int m, int n, int[][] ops) {
        if(ops.length==0){
            return m*n;
        }
        int minM = ops[0][0] ;
        int minN = ops[0][1] ;
        for(int i = 0;i<ops.length;i++){
            if(minM>ops[i][0]){
                minM=ops[i][0];
            }
            if(minN>ops[i][1]){
                minN=ops[i][1];
            }
        }
        return minM*minN;
    }
}
```
