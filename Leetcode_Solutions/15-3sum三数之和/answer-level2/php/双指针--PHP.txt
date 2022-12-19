### 解题思路
排序后，遍历元素，使用两指针在当前元素后面查找。注意去重。

之前在某公司面试遇到这题，采用的是分3个数组的方式，面试官不太满意。

### 性能
执行用时 :176 ms, 在所有 PHP 提交中击败了96.88%的用户
内存消耗 :24.7 MB, 在所有 PHP 提交中击败了16.66%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[][]
     */
    function threeSum($nums) {
        $res = [];
        sort($nums);
        $len = count($nums);
        for ($i = 0; $i < $len; $i++) {
            if ($nums[$i] > 0) continue;

            if ($i > 0 && $nums[$i -1] == $nums[$i]) continue;

            $front = $i + 1;
            $rear = $len - 1;
            while ($front < $rear) {
                $sum = $nums[$i] + $nums[$front] + $nums[$rear];
                if ($sum == 0) {
                    $res[] = [$nums[$i], $nums[$front], $nums[$rear]];
                    while ($front < $rear && $nums[$front] == $nums[$front + 1]) $front++;
                    while ($front < $rear && $nums[$rear - 1] == $nums[$rear]) $rear--;
                    $front++;
                    $rear--;
                } elseif ($sum > 0) {
                    $rear--;
                } else {
                    $front++;
                }
            }
        }

        return $res;
    }
}
```

### 算法复杂度
- 时间复杂度: O(N ^ 2)
- 空间复杂度：O（N）

### 参考
[https://leetcode-cn.com/problems/3sum/solution/hua-jie-suan-fa-15-san-shu-zhi-he-by-guanpengchn/](https://leetcode-cn.com/problems/3sum/solution/hua-jie-suan-fa-15-san-shu-zhi-he-by-guanpengchn/)