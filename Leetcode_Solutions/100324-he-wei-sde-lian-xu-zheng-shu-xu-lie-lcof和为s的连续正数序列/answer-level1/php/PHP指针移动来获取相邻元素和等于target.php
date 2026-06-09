### 解题思路
满足数据的只有target前一半的数据，
第一步就是选择前一半的数据。
第二步对相邻的元素相加，根据不同条件来移动两个不同的指针，直到退出。
![image.png](https://pic.leetcode-cn.com/0be22cc7a786a2915fef5d81aba4f003f120ca25d107bf0cf539b3b6759138c4-image.png)
总结：暂时想到这个算法，执行时间偏长，有更好的再来完善。

### 代码

```php
class Solution {

    /**
     * @param Integer $target
     * @return Integer[][]
     */
    function findContinuousSequence($target) {
        $middle = $target % 2 ? ($target + 1) / 2 : $target / 2;

        $i = 1;
        $j = 1;
        $result = [];

        while ($i < $middle) {
            $end = $i + $j;

            if ($end > $middle) {
                $j = 1;
                $i++;
                continue;
            }

            $total = ($i + $end) / 2 * ($j + 1);

            if ($total == $target) {
                $result[] = range($i, $end);
                $i++;
            } elseif ($total < $target) {
                $j++;
            } else {
                $i++;
                $j = 1;
            }
        }

        return $result;
    }
}
```