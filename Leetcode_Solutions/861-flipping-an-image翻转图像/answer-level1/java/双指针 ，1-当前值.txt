### 解题思路
通过观察两次变换很容易得出
1. 左右的值不相等的时候，不需要进行变换
2. 左右的值相等的时候，需要进行1 - 当前值 操作变换即可
3. 奇数长度的中间值进行 1 - 当前值 操作

### 代码

```java
class Solution {
    // 双指针 1- 变换
    public int[][] flipAndInvertImage(int[][] A) {
        for (int i = 0; i < A.length; i++) {
            // 双指针交换对称值
            int r = 0,l = A[i].length - 1;
            while (r <= l) {
                int rval = A[i][r],lval = A[i][l];
                // 如果下标相等证明是中间值，只需要进行变化即可
                if (r == l) {
                    A[i][r] = 1 - rval;
                } 
                // 如果需要两边的值相等时，则两边的值需要变换
                else if (rval == lval) {
                    A[i][r] = 1 - rval;
                    A[i][l] = 1 - lval;
                }
                r++;
                l--;
            }
        }
        return A;
    }
}
```