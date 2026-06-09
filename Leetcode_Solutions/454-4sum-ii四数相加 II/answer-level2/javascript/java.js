```
class Solution {
    public int fourSumCount(int[] A, int[] B, int[] C, int[] D) {
        HashMap<Integer,Integer> map = new HashMap<>();
        int res;
        int count=0;
        for(int i=0;i<A.length;i++){
            for(int k=0;k<B.length;k++){
                res= A[i]+B[k];
                if(!map.containsKey(res)) {
                    map.put(res,1);
                }
                else map.put(res,map.get(res)+1);
                res=0;
            }
        }
        for(int j=0;j<C.length;j++){
            for(int l=0;l<D.length;l++){
                res= 0-C[j]-D[l];

                if(map.containsKey(res)) {
                    count=count+map.get(res);
            }
        }
    }
    return count;
    }
}
```
