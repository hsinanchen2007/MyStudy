### 解题思路
1. 暴力破解
 看到这道题，第一个想到的就是暴力破解方式，最后去重。一顿操作猛如虎，最后超时了。
2. 排序，双指针方式
 1. a+b+c=0 那么 0-c=a+b，有了求解公式就好办了
 2. 限制条件是不同有相同的三元。如果求解之后再去重时间复杂度将会是n2，不建议最后去重。
 3. 参考我们小学数学的解法，一串无序列数字想加，得到另一个结果。如果这一串很多，先排序，再首尾想加（口算当然是大数+小数方便计算）。排序的时间复杂度是 O(logn)可以接受
 4. 考虑去重的问题，有两步。第一：数组是有序的，如果我们上一个操作中处理过这个数字了，那么我们下一步中就不要再继续处理了。第二：如果首尾想加的结果是我们想要的值。那么指针偏移到下一个值的指针（如果下次再处理这个值，说明重复了）
 5. 参考地址：https://github.com/MisterBooo/LeetCodeAnimation/blob/master/notes/LeetCode%E7%AC%AC15%E5%8F%B7%E9%97%AE%E9%A2%98%EF%BC%9A%E4%B8%89%E6%95%B0%E4%B9%8B%E5%92%8C.md
### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[][]
     */
    function threeSum($nums) {
        sort($nums);
        $highIndex = count($nums) - 1;
        // 如果最小值0那么无需处理了
        if ($nums[0] > 0) return [];

        $res = [];
        for ($i = 0; $i <= $highIndex; $i++) {

            // 数组是有序的，大于0的数据想加将会不成立
            if ($nums[$i] > 0) break;

            // 如果 i与i-1值相同，说明上一次比较过了
            if ($i > 0 && $nums[$i] == $nums[$i-1]) continue;

            // 要对比的值
            $target = 0 - $nums[$i];

            $low = $i + 1;
            $high = $highIndex;

            // 低位点小于高位点
            while ($low < $high) {
                if ($nums[$low] + $nums[$high] == $target) {
                    $res[] = [$nums[$i], $nums[$low], $nums[$high]];
                    // 因为返回的结果需要去重，并且数据是已经排序好的
                    // 所以如果low == low+1 说明数据组合会重合。因此将 low 偏移到下一位
                    while ($low < $high && $nums[$low] == $nums[$low+1]) { // low 重复的情况
                        $low ++;
                    }

                    while ($low < $high && $nums[$high] == $nums[$high-1]) { //  high 重复的情况
                        $high --;
                    }

                    // low 与 high 这对组合已经使用过，因此需要偏移
                    $low ++; $high --;

                } else if ($nums[$low] + $nums[$high] < $target) { // 两数之和大于结果，缩小区间
                    $low ++;
                } else {
                    $high --;
                }
            }
        }

        return $res;
    }
}
```