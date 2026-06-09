### 解题思路
对矩阵的每一行进行双向遍历。
遍历的当前行左右两端元素相同则取反，相异则不需做修改。

### 代码

```java
class Solution {
    public int[][] flipAndInvertImage(int[][] A) {
        for (int i = 0; i < A.length; i++) {
            for (int j = 0, k = A[i].length-1; j <= k; j++, k--) {
                //当前行元素个数为奇数时，中间的元素置反
                if (j == k) {
                    A[i][j] = 1 - A[i][j];
                    break;
                }
                //左右两端相同取反，相异则不需做修改
                if (A[i][j] == A[i][k]) {
                    A[i][j] = 1 - A[i][k];
                    A[i][k] = A[i][j];
                }
                
            }
        }
        return A;
    }
}
```