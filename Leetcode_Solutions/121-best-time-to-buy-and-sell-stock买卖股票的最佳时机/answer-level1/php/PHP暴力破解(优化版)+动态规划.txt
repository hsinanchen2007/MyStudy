### 解题思路
暴力破解
1. 找到最低值和最高值
2. 优化内层遍历次数
动态规划
1. 动态找出最低值
2. 动态更新下一天的利润
### 代码 暴力破解(优化)+动态规划
```php []
class Solution {

    /**
     * @param Integer[] $prices
     * @return Integer
     */
    function maxProfit($prices) {
        $money = 0;

        $count = count($prices);

        for ($i=0;$i<$count;$i++) {
            # 优化内层循环次数
            if ($i+1 != $count && $prices[$i+1] < $prices[$i]) {
                continue;
            }
            for ($j=$i+1;$j<$count;$j++) {
                if ($prices[$j] > $prices[$i]) {
                    $money = max($money,$prices[$j] - $prices[$i]);
                }
            }
        }
        return $money;
    }
}
```
```php []
class Solution {

    /**
     * @param Integer[] $prices
     * @return Integer
     */
    function maxProfit($prices) {
        $money = 0;
        $fisrt_val = $prices[0];

        $count = count($prices);

        for ($i=1;$i<$count;$i++) {
            if ($prices[$i] < $fisrt_val) {
                $fisrt_val = $prices[$i];
            } elseif ($prices[$i] - $fisrt_val > $money) {
                $money = $prices[$i] - $fisrt_val;
            }
        }
        return $money;
    }
}
```
