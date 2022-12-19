### 解题思路
这题是我第一次做的比较快并且一次提交就通过了的题^o^.
这题的思路就是遍历所有的点,看以哪个点为起点的递增路径最长.对于每一个点,他的下一步只能往四个方向走,而且下一个点必须比它大,在剩下的点中,选出以剩下的点为起点时增序路径较长的点.对于一些已经计算过的起点,我们就可以用一个和martix相同大小的二维数组来储存结果.这样,每个点只需要计算一次路径,时间复杂度O(mn).

### 代码

```java
class Solution {
   
    int[][] dp;

    int l1, l2, ll1, ll2;

    public int longestIncreasingPath(int[][] matrix) {
        l1 = matrix.length;
        if (l1 == 0) {
            return 0;
        }
        ll1 = l1 - 1;
        l2 = matrix[0].length;
        if (l2 == 0) {
            return 0;
        }
        ll2 = l2 - 1;
        dp = new int[l1][l2];
        int temp, result = 0;
        for (int i = 0; i < l1; i++) {
            for (int j = 0; j < l2; j++) {
                temp = findLongestLength(matrix, i, j);
                result = temp > result ? temp : result;
            }
        }
        return result;
    }

    public int findLongestLength(int[][] matrix, int x, int y) {
        if (dp[x][y] != 0) {
            return dp[x][y];
        }
        int temp = 0;
        int result;
        if (x > 0 && matrix[x - 1][y] > matrix[x][y]) {
            result = findLongestLength(matrix, x - 1, y);
            temp = result > temp ? result : temp;
        }
        if (x < ll1 && matrix[x + 1][y] > matrix[x][y]) {
            result = findLongestLength(matrix, x + 1, y);
            temp = result > temp ? result : temp;
        }
        if (y > 0 && matrix[x][y - 1] > matrix[x][y]) {
            result = findLongestLength(matrix, x, y - 1);
            temp = result > temp ? result : temp;
        }
        if (y < ll2 && matrix[x][y + 1] > matrix[x][y]) {
            result = findLongestLength(matrix, x, y + 1);
            temp = result > temp ? result : temp;
        }
        return dp[x][y] = ++temp;
    }
}
```