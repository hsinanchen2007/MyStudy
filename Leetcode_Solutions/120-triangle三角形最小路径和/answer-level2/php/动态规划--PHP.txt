### 解题思路
动态规划，原地修改。**重点是当前元素和他下一行相邻两个元素的关系。**

算法：
- 状态，dp[i][j]表示第i行第j列最小路径和
- 状态转移方程，dp[i][j] = dp[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1])
- 从最后一行往前遍历，原地修改节省空间。

注意：是三角形，第一行是一个元素，最终dp[0][0]是唯一的。

### 性能
执行用时 :16 ms, 在所有 PHP 提交中击败了94.44%的用户
内存消耗 :16.8 MB, 在所有 PHP 提交中击败了63.16%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $triangle
     * @return Integer
     */
    function minimumTotal($triangle) {
        for ($i = count($triangle) - 2; $i >=0; $i--) {
            for ($j = 0; $j < count($triangle[$i]); $j++) {
                $triangle[$i][$j] += min($triangle[$i + 1][$j], $triangle[$i + 1][$j + 1]);
            }
        }

        return $triangle[0][0];
    }
}
```

### 算法复杂度
- 时间复杂度 O(N ^ 2)
- 空间复杂度 O(1)

### 参考
[https://leetcode-cn.com/problems/triangle/comments/2532](https://leetcode-cn.com/problems/triangle/comments/2532)