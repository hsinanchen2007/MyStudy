### 解题思路
此处撰写解题思路
两种解题方法，第一种即暴力法，遍历计数；第二种二分查找，先找到target所在的下标位置,然后再两边延伸，统计个数
### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer
     */
    function search($nums, $target) {
        //思路一 暴力法 2分钟
        /*
        $count = 0;
        foreach ($nums as $num) {
            if ($num == $target) {
                $count ++;
            }
            if ($num > $target) {
                break;
            }
         }
         return $count;
         */
         //思路二 二分查找 10分钟
         $count = 0;
         $end = count($nums) - 1;
         $start = 0;
         while ($start <= $end) {
             $mid = (int)(($start + $end) >> 1);
             if ($nums[$mid] === $target) {
                 break;
             } elseif ($nums[$mid] < $target) {
                 $start = $mid + 1;
             } else {
                 $end = $mid - 1;
             }
         }
          
         if ($nums[$mid] !== $target) {
             return 0;
         } else {
             $left = $right = $mid;
             while ($nums[$left] === $target) {
                 $count ++;
                 $left --;
             }
             while ($nums[$right] === $target) {
                 $count ++;
                 $right ++;
             }
         }
         return $count - 1;
    }
}
```