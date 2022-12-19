### 解题思路
过滤最大最小值，第二处过滤最大值有num[i]较小，后num[j]数值还有大值，不可break跳出for循环，推荐先练习三数之和，双指针同理
附大佬链接，[超级思路](https://leetcode-cn.com/problems/4sum/solution/ji-bai-9994de-yong-hu-you-dai-ma-you-zhu-shi-by-yo/)
### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[][]
     */
    function fourSum($nums, $target) {
        sort($nums);
        $total = count($nums);
        $ret = [];
        if($total < 4) return $ret;

        for($i = 0; $i < $total-3; $i++){
            if($i > 0 && $nums[$i] == $nums[$i - 1]) continue;

            // 当前最小值
            $min1 = $nums[$i] + $nums[$i+1] + $nums[$i+2] + $nums[$i+3];
            if($min1 > $target) break;

            // 当前最大值
            $max1 = $nums[$i] + $nums[$total-1] + $nums[$total-2] + $nums[$total-3];
            if($max1 < $target) continue;

            for($j = $i+1; $j < $total-2; $j++){
                if($j > $i+1 && $nums[$j] == $nums[$j-1]) continue;

                // 当前最小值
                $min = $nums[$i] + $nums[$j] + $nums[$j+1] + $nums[$j+2];
                if($min > $target) continue;

                // 当前最大值
                $max = $nums[$i] + $nums[$j] + $nums[$total-1] + $nums[$total-2];
                if($max < $target) continue;
                
                $left = $j + 1;
                $right = $total - 1;
                while($left < $right){
                    $sum = $nums[$i] + $nums[$j] + $nums[$left] + $nums[$right];
                    if($sum == $target){
                        $ret[] = [$nums[$i],$nums[$j],$nums[$left],$nums[$right]];
                        while($left < $right && $nums[$left] == $nums[$left + 1]) $left++;
                        while($left < $right && $nums[$right] == $nums[$right - 1]) $right--;
                        $left++;
                        $right--;
                    }elseif($sum > $target){
                        $right--;
                    }elseif($sum < $target){
                        $left++;
                    }
                }

            }
        }
        return $ret;
    }
}
```