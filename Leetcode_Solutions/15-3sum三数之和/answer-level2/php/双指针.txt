### 解题思路
 $low,$high指针

### 代码

```php
/**
    1. 数组分为两个数组，正数+0一个数组，负数一个数组
    2. 遍历负数组，判断是否有和正数组相加为0的数
*/
class Solution {
    /**
     * @param Integer[] $nums
     * @return Integer[][]
     */
    function threeSum($nums) {
        $len = count($nums);
        if($len < 3) return [];
        $low = 1;
        $high = $len - 1;
        $result = [];
        // 先对$nums进行排序
        sort($nums);
        for($i = 0; $i < $len; $i++) {
            $low = $i + 1;
            $high = $len - 1;
            $target = -$nums[$i];
            if($nums[$i] === $nums[$i-1]) continue;
            while($low < $high) {
                if($nums[$low] + $nums[$high] === $target) {
                    array_push($result, [$nums[$i], $nums[$low], $nums[$high]]);
                    while($nums[$low] === $nums[++$low]) continue;
                    --$high;
                } else if($nums[$low] + $nums[$high] > $target) {
                    --$high;
                } else {
                    ++$low;
                }
            }
        }
        return $result;
    }
}
```