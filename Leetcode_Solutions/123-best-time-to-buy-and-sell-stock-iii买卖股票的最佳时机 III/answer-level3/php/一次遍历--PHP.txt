### 解题思路
定义四个变量分别记录第i天，第一次买和卖的最大收益，第二次买和卖的最大收益。遍历一次，每一天都尝试买卖如果有收益，就跟新(操作)。

注意：+ -price可以理解为入账和出账。

### 性能
执行用时 :20 ms, 在所有 PHP 提交中击败了88.89%的用户
内存消耗 :16.7 MB, 在所有 PHP 提交中击败了88.24%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[] $prices
     * @return Integer
     */
    function maxProfit($prices) {
        $one_buy = $two_buy = PHP_INT_MIN;
        $one_sell = $two_sell = 0;

        foreach ($prices as $price) {
            $one_buy = max($one_buy, -$price);
            $one_sell = max($one_sell, $one_buy + $price);
            $two_buy = max($two_buy, $one_sell - $price);
            $two_sell = max($two_sell, $two_buy + $price);
        }

        return $two_sell;
    }
}
```

### 算法复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(1)

### 思考
这么感觉买卖来多次呢，不止2次

### 参考
[https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/comments/10208](https://leetcode-cn.com/problems/best-time-to-buy-and-sell-stock-iii/comments/10208)
