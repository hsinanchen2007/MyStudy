### 解题思路
执行用时 :
1 ms
, 在所有 Java 提交中击败了
100.00%
的用户
内存消耗 :
38.8 MB
, 在所有 Java 提交中击败了
84.44%
的用户

最简单粗暴的解法，不知道为什么超越这么多，尴尬

### 代码

```java
class Solution {
    public int[][] matrixReshape(int[][] nums, int r, int c) {
        int row = nums.length;
        int col = nums[0].length;
        if (r * c != row * col) {
            return nums;
        }

        int[] tmp = new int[col * row];
        int index = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                tmp[index++] = nums[i][j];
            }
        }

        int[][] results = new int[r][c];
        int size = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                results[i][j] = tmp[size];
                size++;
            }
        }
        return results;
    }
}
```