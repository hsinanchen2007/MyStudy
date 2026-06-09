### 解题思路
双指针咻咻咻，严重感谢[@guanpengchn](/u/guanpengchn/)的不吝赐教

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[][]
     */
    function threeSum($nums) {
        $size = count($nums);
        if($size < 3) return [];

        sort($nums);
        $result = [];

        for($i=0;$i<$size;$i++){
            //升幂排列后如果数组第一个数字大于零，表明不可能有三个数之和为0
            if($nums[$i] > 0) break;

            //如果当前数字跟之前数字相同，则跳过
            if($i>0 && $nums[$i] == $nums[$i-1]) continue;

            //设定左右边缘
            $left = $i + 1;
            $right = $size - 1;

            while($left < $right){
                //做三数之和（当前for loop点，此点右边往中心靠拢的两点）
                $sum = $nums[$i] + $nums[$left] + $nums[$right];
                if($sum == 0){
                    //成功拼凑和为0，记录三个数字
                    $result[] = [$nums[$i], $nums[$left], $nums[$right]];

                    //左右开弓，确保跳过相同数字
                    while($left < $right && $nums[$left] == $nums[$left + 1]) $left++;
                    while($left < $right && $nums[$right] == $nums[$right - 1]) $right++;

                    $left++;
                    $right--;
                }
                //之和小于0，说明需要一个大一点的数字，左边往右靠
                elseif ($sum < 0) $left++;
                //之和大于0，说明需要一个小一点的数字，右边网左靠
                elseif ($sum > 0) $right--;
            }
        }

        return $result;

    }
}
```