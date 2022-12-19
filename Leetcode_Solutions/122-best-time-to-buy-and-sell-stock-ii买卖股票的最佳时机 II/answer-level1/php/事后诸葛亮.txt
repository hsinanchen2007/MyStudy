### 解题思路
站在股票价格都已经出来的高度上，我可以知道当天的价格，以及预知后一天的价格。
如果后一天的价格比当天高，当天就买入，后一天就卖出。

可以看成是事后复盘。故称此方法为“事后诸葛亮”。

### 代码

```php
class Solution {

    /**
     * @param Integer[] $prices
     * @return Integer
     */
    function maxProfit($prices) {
        $profit = 0;
        for ($i = 1; $i < count($prices); $i++) {
            if ($prices[$i] > $prices[$i - 1]) {
                $profit += $prices[$i] - $prices[$i - 1];
            }
        }

        return $profit;
    }
}
```

### 注意
遍历的终止条件似乎定义一个变量可以避免每次计算，实际耗时更长, 内存却节省了, 很奇怪。待验证。

0、不定义变量的方式
执行用时 :12 ms, 在所有 php 提交中击败了98.37%的用户
内存消耗 :16.9 MB, 在所有 php 提交中击败了6.02%的用户

1、定义变量的方式
```
$len = count($prices);
```
执行用时 :16 ms, 在所有 php 提交中击败了88.62%的用户
内存消耗 :16.7 MB, 在所有 php 提交中击败了6.02%的用户
