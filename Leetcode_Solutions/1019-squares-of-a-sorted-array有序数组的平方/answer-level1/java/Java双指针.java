### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
    public int[] sortedSquares(int[] A) {
        // 双指针向内走
        int l = 0, r = A.length - 1, k = A.length - 1;
        int[] B = new int[A.length];
        while (k >= 0){
            if (A[l] * A[l] <= A[r] * A[r]){
                B[k--] = A[r] * A[r];
                r -= 1;
            }
            else{
                B[k--] = A[l] * A[l];
                l += 1;
            }
        }
        return B;
    }
}
```