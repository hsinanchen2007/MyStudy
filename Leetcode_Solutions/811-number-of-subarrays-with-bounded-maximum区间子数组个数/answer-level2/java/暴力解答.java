```
class Solution {
    public int numSubarrayBoundedMax(int[] A, int L, int R) {
        int count = 0;               
        for(int i=0;i<A.length;i++){
            if(A[i]>R){
                continue;
            }
            boolean flag = false;    
            for(int j=i;j<A.length;j++){   
                if(A[j]>R){
                    break;
                }                
                if(A[j]>=L){
                    flag =true;
                }
                if(flag){
                    count++;
                }                
            }
        }
        return count;
    }
}
```

