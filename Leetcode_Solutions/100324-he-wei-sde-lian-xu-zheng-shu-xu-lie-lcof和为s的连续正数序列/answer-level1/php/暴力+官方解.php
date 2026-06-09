### 解题思路
暴力与官方解

### 代码

```php
class Solution {

    /**
     * @param Integer $target
     * @return Integer[][]
     */
    function findContinuousSequence($target) {
        // $cur_count = 1;
        // $final = [];
        // while($cur_count < $target){
        //     $cur_sum = 0;
        //     $cur_nums = [];
        //     $inner_count = $cur_count;
        //     while($cur_sum < $target){
        //         $cur_sum += $inner_count;
        //         $cur_nums[] = $inner_count;
        //         if($cur_sum == $target){
        //             $final[] = $cur_nums;
        //             break;
        //         }
        //         $inner_count++;
        //     }
        //     $cur_count++;
        // }
        // return $final;

        $result = [];
        $small = 1;
        $big = 2;
        // 滑动窗口
        while ($small < $big && $small <= $target / 2) {
            $sum = ($small + $big) * ($big - $small + 1) / 2;
            if ($sum == $target) {
                $result[] = range($small, $big, 1);
                $small++;
                $big++;
            } elseif ($sum < $target) {
                $big++;
            } else {
                $small++;
            }
        }
        return $result;

    }
}
```