### 解题思路
双指针，只要找到两边最高点就开始做减法

### 代码

```php
class Solution {

    /**
     * @param Integer[] $height
     * @return Integer
     */
    function trap($height) {
        // $count = count($height);
        // if ($count <= 1) {
        //     return 0;
        // }

        // $result = 0;
        // $maxLeft = $maxRight = array_fill(0, $count, 0);
        // // 从左向右计算左侧最高
        // for ($i = 1; $i < $count; ++$i) {
        //     $maxLeft[$i] = max($maxLeft[$i - 1], $height[$i - 1]);
        // }

        // // 从右向左计算右侧最高
        // for ($i = $count - 1; $i > 0; --$i) {
        //     $maxRight[$i] = max($maxRight[$i + 1], $height[$i + 1]);
        // }

        // for ($i = 1; $i < $count - 1; ++$i) {
        //     $diff = min($maxLeft[$i], $maxRight[$i]) - $height[$i];
        //     if ($diff > 0) {
        //         $result += $diff;
        //     }
        // }

        // return $result;

        $ans = 0;
        if (empty($height)) return $ans;
        $len = count($height);
        $left = 0; 
        $right = $len -1;

        $maxLeft = 0;
        $maxRight = 0;

        while($left < $right) {
            if ($height[$left] < $height[$right]) {
                if($height[$left] > $maxLeft){
                    $maxLeft = $height[$left];
                }
                else{
                    $ans += $maxLeft - $height[$left];
                }
                $left++;
            } else {
                if($height[$right] > $maxRight){
                    $maxRight = $height[$right];
                }
                else{
                    $ans += $maxRight - $height[$right];
                }
                $right--;
            }
        }  
        return $ans;

    }
}
```