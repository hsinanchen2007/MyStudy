### 解题思路
看代码注释吧

### 代码

```php
class Solution {

    /**
     * @param Integer[] $A
     * @return Integer
     */
    function minIncrementForUnique($A) {
         # 贪心算法
        sort($A); // 排序后数组递增，会出现2种情况（A01:相邻的N个相等，A02:相邻的不等并且递增顺序）
        $count = 0;
        for ($i=1; $i < count($A); $i++) { 
            if ($A[$i - 1] >= $A[$i]):
                // 前一个大于等于当前的，也就是A01情况
                // 1、操作次数增加 X 次，X = 前一个 - 当前 + 1， 比如经过几次循环，出现：【...,6，4】，那么4+（6-4+1）=7
                // 2、将当前的值改为比前一个大1个数
                $count += $A[$i - 1] - $A[$i] + 1;
                $A[$i] = $A[$i - 1] + 1;
            endif;
        }
        return $count;
    }
}
```