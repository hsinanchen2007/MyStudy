### 解题思路
思路高票答案都给出了，下面给出 PHP 实现代码。

知识点：`usort` 函数

### 代码

```php
class Solution {

    /**
     * @param Integer[][] $costs
     * @return Integer
     */
    function twoCitySchedCost($costs) {
        // 贪心算法
        // 自定义排序，根据两个数值之差进行排序
        usort($costs, function ($a, $b) {
            if (($a[0] - $a[1]) == ($b[0] - $b[1])) {
                return 0;
            }

            return ($a[0] - $a[1]) < ($b[0] - $b[1]) ? -1 : 1;
        });

        $length = count($costs);
        $sum = 0;
        foreach ($costs as $key => $cost) {
            if ($key < $length / 2) {
                $sum += $cost[0];
            } else {
                $sum += $cost[1];
            }
        }

        return $sum;
    }
}
```