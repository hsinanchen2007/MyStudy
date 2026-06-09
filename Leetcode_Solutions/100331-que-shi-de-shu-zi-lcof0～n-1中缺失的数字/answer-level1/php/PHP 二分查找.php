### 解题思路
此处撰写解题思路
本题我的思路是二分法，这其实也是二分查找的一种变种，只不过从查找存在数变成不存在数，由于是已排序且+1递增的，所以数组的key和value即存在相等的关系；二分法时，跳出循环的终止条件即start==end,此时start代表的也即是缺失的值。因为此时查找到最终start!=nums[start]，也即结果
### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function missingNumber($nums) {
        //二分查找 变种
        $end = count($nums);
        $start = 0;

        while ($start <= $end) {
            $mid = (int)(($start + $end) >> 1);
            if ($nums[$mid] == $mid) {
                $start = $mid + 1;
            } else {
                $end = $mid;
            }
            if ($start == $end) {
                break;
            }
        }
        
        return $start;

    }
}
```