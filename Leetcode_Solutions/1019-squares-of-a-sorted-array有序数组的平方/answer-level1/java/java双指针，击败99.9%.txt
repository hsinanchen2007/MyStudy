```
java
```
class Solution {

    public int[] sortedSquares(int[] A) {
        int left = 0;
        int right = A.length - 1;
        int[] ans = new int[right + 1];
        int p = right;
        while(left <= right){
            if(Math.abs(A[left]) > Math.abs(A[right])){
                ans[p--] = A[left] * A[left];
                left ++;
            }else{
                ans[p--] = A[right] * A[right];
                right --;
            }
        }
        return ans;
    }
}