```
class Solution {
    public boolean isMonotonic(int[] A) {
        if(A.length <= 2) {
            return true;
        }
        //start变量记录起始位
        int start = 0;
        //确定起始位
        for(int i = 0; i < A.length - 1; i++) {
            if(A[i] != A[i + 1]) {
                start = i;
                break;
            }
        }
        //确定符号，两种情况
        if(A[start] < A[start + 1]) {
            for(int x = start + 2; x < A.length; x++) {
                if(A[x] < A[x - 1]) {
                    return false;
                }
            }
            return true;
        } else {
            for(int x = start + 2; x < A.length; x++) {
                if(A[x] > A[x - 1]) {
                    return false;
                }
            }
             return true;
        }
    }
}
```
