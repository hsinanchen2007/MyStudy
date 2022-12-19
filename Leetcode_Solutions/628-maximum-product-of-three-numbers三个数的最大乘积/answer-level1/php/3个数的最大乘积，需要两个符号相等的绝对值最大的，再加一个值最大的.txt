### 解题思路
3个数的最大乘积，需要两个符号相等的绝对值最大的，再加一个值最大的
遍历一遍取出最大的三个，最小的两个（有负数则为绝对值最大）
结果 = max(最小的两个的乘积, 第二大和第三大的两个的乘积) * 最大值

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function maximumProduct($nums) {
        $max1 = null;
        $max2 = null;
        $max3 = null;
        $min1 = null;
        $min2 = null;
        foreach ($nums as $num) {
            if (is_null($min1)) {
                $min1 = $num;
            }elseif ($min1 > $num) {
                $min2 = $min1;
                $min1 = $num;
            }elseif (is_null($min2) || $min2 > $num) {
                $min2 = $num;
            }

            if (is_null($max1)) {
                $max1 = $num;
                continue;
            }
            if ($max1 < $num) {
                list($max1, $num) = [$num, $max1];
            }
            if (is_null($max2)) {
                $max2 = $num;
                continue;
            }
            if ($max2 < $num) {
                list($max2, $num) = [$num, $max2];
            }
            if (is_null($max3)) {
                $max3 = $num;
                continue;
            }
            if ($max3 < $num) {
                list($max3, $num) = [$num, $max3];
            }
        }
        return max($max1 * $max2 * $max3, $min1 * $min2 * $max1);
    }
}
```