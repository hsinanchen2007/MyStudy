### 解题思路
1.用二维数组$dp[$i][]来记录最优解的答案
第$i是0号颜色的最优答案
$dp[$i][0] = min($dp[$i - 1][1], $dp[$i - 1][2]) + $costs[$i][0];
第$i是1号颜色的最优答案
$dp[$i][1] = min($dp[$i - 1][0], $dp[$i - 1][2]) + $costs[$i][1];
第$i是2号颜色的最优答案
$dp[$i][2] = min($dp[$i - 1][0], $dp[$i - 1][1]) + $costs[$i][2];
第$i个房子涂完后的最优答案
$dp[$i][3] = min($dp[$i]);

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $costs
     * @return Integer
     */
    function minCost($costs) {
        if (empty($costs)) return 0;
        $dp[0] = $costs[0];

        $dp[0][3] = min($costs[0]);

        for ($i = 1; $i < count($costs); $i++) {
            $dp[$i][0] = min($dp[$i - 1][1], $dp[$i - 1][2]) + $costs[$i][0];
            $dp[$i][1] = min($dp[$i - 1][0], $dp[$i - 1][2]) + $costs[$i][1];
            $dp[$i][2] = min($dp[$i - 1][0], $dp[$i - 1][1]) + $costs[$i][2];
            $dp[$i][3] = min($dp[$i]);
        }

        return $dp[count($costs) - 1][3];
    }
}
```