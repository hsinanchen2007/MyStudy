```
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function maximumProduct($nums) {
        sort($nums);
        $con = count($nums);
        
        $n1 = $nums[0];
        $n2 = $nums[1];

        $n3 = $nums[$con-1];
        $n4 = $nums[$con-2];
        $n5 = $nums[$con-3];
        
        if ($n1 >= 0) {
            $c = $n3*$n4*$n5;
        } else {
            $c = max($n3*$n4*$n5,$n1*$n2*$n3);
        }

        return $c;
    }
}
```
