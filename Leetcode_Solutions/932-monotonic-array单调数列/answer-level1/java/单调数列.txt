思路：通过比较数组中第一个元素和最后一个元素的大小，判断是单调递增、单调递减还是所有元素相等，然后通过一次遍历比较相邻元素的大小，只要有一次不满足单调顺序，则返回false。
```
class Solution {
    public boolean isMonotonic(int[] A) {
        if(A == null) return false;
        if(A.length == 1) return true;
        int len = A.length;
        if(A[0] < A[len-1]){
            for(int i = 1; i < len; i++){
                if(A[i] < A[i-1]){
                    return false;
                }
            }
        } else if(A[0] > A[len-1]){
            for(int i = 1; i < len; i++){
                if(A[i] > A[i-1]){
                    return false;
                }
            }
        } else if(A[0] == A[len-1] && len > 2){
            for (int i = 1; i < len; i++) {
                if (A[i] != A[i-1]){
                    return false;
                }
            }
        } else {
            return true;
        }
        return true;
    }
}
```
