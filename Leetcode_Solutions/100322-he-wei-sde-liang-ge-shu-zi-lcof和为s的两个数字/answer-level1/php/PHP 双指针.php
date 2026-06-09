### 解题思路
此处撰写解题思路
本题和官方题库里的两数之和一样，我采用了双指针方式，考虑的原因是，首先是排序好的数组，双指针处理，更简单方便，无需多言
### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        //双指针
        $end = count($nums) -1 ;
        $start = 0;
        while ($start < $end) {
            if ($nums[$start] + $nums[$end] == $target) {
                return [$nums[$start], $nums[$end]];
            } elseif ($nums[$start] + $nums[$end] < $target) {
                $start ++;
            } else {
                $end --;
            }
        }
        return [];
    }
}
```