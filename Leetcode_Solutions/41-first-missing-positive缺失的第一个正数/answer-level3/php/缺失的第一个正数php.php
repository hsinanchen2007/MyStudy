### 解题思路
还是参考了官方的解法自己理解了稍加改动！

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function firstMissingPositive($nums) {
        $count = count($nums);
        // 如果数组为空，那么缺失的一定是最小元素为1
        if ($count == 0) return 1;

        // 如果数组只有一个元素
        if ($count == 1) {
            // 如果是1，那么缺失的一定是2
            if ($nums[0] == 1) return 2;

            // 如果不是1，那么缺失的一定是1
            return 1;
        }

        // 我们将0，负数，大于 count 的数都标记为1，但是这需要数据中一定含有1，否则会有 bug，因此如果没有找到1，那么直接返回1
        $has1 = false; // 是否存在1
        for ($i=0; $i<$count; $i++) {
            if ($nums[$i] == 1 && $has1 == false) {
                // 1 是存在的
                $has1 = true;
            } else if ($nums[$i] <= 0 || $nums[$i] > $count) {
                // 将不考虑的数据标记为1
                $nums[$i] = 1;
            }
        }

        // 数据中不存在1，返回1
        if (! $has1 ) return 1;

        // 现在数据默认都是正数，我们用负数标记这个数据存在，那么正数表示数据的不存在
        for ($i=0; $i<$count; $i++) {

            $a = abs($nums[$i]);

            // 用$nums[0]来标记数组最后一个元素（因为新的标记偏移从1开始的）
            if ($a == $count) {
                // 负数标记数组最后一个元素不缺失
                $nums[0] = - $nums[0];
            } else {
                // 标记这个元素存在
                $nums[$a] = - abs($nums[$a]);
            }
        }

        // 第一个正数（没有标记）的下标就是缺失的最小数
        for ($i=1; $i<$count; $i++) {
            if ($nums[$i] > 0 ) return $i;
        }

        // 0 没有被标记，缺失的就是最后一个
        if ($nums[0] > 0) return $count;

        // 0标记了，缺失的是下一个
        return $count + 1;
    }
}
```