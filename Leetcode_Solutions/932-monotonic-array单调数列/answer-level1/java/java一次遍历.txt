一次遍历，用两个变量记录单调递增或递减的长度，如果长度正好等于A.length，则为单调数列

```java
class Solution {
    public boolean isMonotonic(int[] A) {
        if(A.length <= 2) return true;
        int count1 = 1, count2 = 1;
        for(int i = 1; i < A.length; i++){
            if(A[i] > A[i-1]){
                count1++;
            }else if(A[i] < A[i-1]) {
                count2++;
            }else{
                count1++;
                count2++;
            }
        }
        if(count1 == A.length || count2 == A.length){
            return true;
        }else{
            return false;
        }
    }
    
}
```