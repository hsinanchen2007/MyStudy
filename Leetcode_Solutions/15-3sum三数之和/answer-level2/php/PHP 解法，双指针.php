### 解题思路
1. 首先剔除一些特殊情况：数组元素个数小于3；排序后最小值大于0；排序后最大值小于0
2. 对数组排序
3. 从第一个元素开始，遍历至倒数第三个元素
4. 每一次遍历中，使用双指针处理该元素右侧的数组，问题基本转化为 twoSum
5. 处理特殊情况，出现连续的相同数字，就可以跳过
6. 代码效率不高，但逻辑清晰易懂

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[][]
     */
    function threeSum($nums) {
        $length = count($nums);
        if ($length < 3) {
            return [];
        }

        sort($nums);
        if ($nums[0] > 0 || end($nums) < 0) {
            return [];
        }

        $result = [];
        for ($i = 0; $i <= $length - 3; ++$i) {
            // 去掉重复的
            if ($i > 0 && $nums[$i] == $nums[$i - 1]) {
                continue;
            }
            $left = $i + 1;
            $right = $length - 1;
            while ($left < $right) {
                $sum = $nums[$i] + $nums[$left] + $nums[$right];
                if ($sum == 0) {
                    $result[] = [$nums[$i], $nums[$left], $nums[$right]];
                    // 去掉重复的
                    while ($left < $right && $nums[$left + 1] == $nums[$left]) {
                        $left++;
                    }

                    while ($left < $right && $nums[$right - 1] == $nums[$left]) {
                        $right--;
                    }
                    $left++;
                    $right--;
                } elseif ($sum < 0) {
                    $left++;
                } else {
                    $right--;
                }
            }
        }

        return $result;
    }
}
```