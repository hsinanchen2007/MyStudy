因为只能交换一次，所以从后往前可以找到第一个不满足非递减的数，然后找一个比他小的数字中最大的数进行交换。

逻辑比较绕，但能证明是最优解。

```
class Solution {
    public int[] prevPermOpt1(int[] A) {
        
        for(int i = A.length - 2; i>=0; i--){
            if(A[i] > A[i+1]){
                
                int tmp_i = i+1;
                
                for(int j = i+2; j<A.length; j++){
                    if(A[j] < A[i] && A[j] > A[tmp_i]){
                        tmp_i = j;
                    }
                }
            
                int tmp = A[tmp_i];
                A[tmp_i] = A[i];
                A[i] = tmp;
                return A;
                
            }
            
        }
        return A;
        
    }
}
```