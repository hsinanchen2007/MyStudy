### 解题思路
之前去BAT面试题遇到过这题，详细说明可参考个人博客：[数组不连续取数问题(不连续取糖果)](http://niliu.me/articles/1839.html)

### 算法
0、采用动态规划，计算取每个盒子最大和, 状态dp[i]
1、初始化第一个状态 dp[0] = $arr[0];
2、初始化第二个状态 dp[1] = max(dp[0], $arr[1]);
3、状态转移方程: 取了当前数，就不能取前一个 dp[i] = max(dp[i-1], dp[i – 2] + $arr[i]);

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function rob($nums) {
        if (count($nums) < 1) {
            return 0;
        }

        $dp[0] = $nums[0];
        $dp[1] = max($dp[0], $nums[1]);
        for ($i = 2; $i < count($nums); $i++) {
            $dp[$i] = max($dp[$i - 1], ($dp[$i - 2] + $nums[$i]));
        }

        return array_pop($dp);
    }
}
```