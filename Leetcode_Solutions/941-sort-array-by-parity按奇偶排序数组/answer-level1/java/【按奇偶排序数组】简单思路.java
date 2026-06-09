思路很简单：遍历数组，偶数从前往后放，奇数从后往前放

```java
class Solution {
    public int[] sortArrayByParity(int[] A) {
        if (A == null || A.length <= 1) {
            return A;
        } 
        int[] B = new int[A.length];
        int i = 0, j = B.length - 1;
        for (int a: A) {
            if (a % 2 == 0) {
                B[i++] = a;
            } else {
                B[j--] = a;
            }
        }
        return B;
    }
}
```