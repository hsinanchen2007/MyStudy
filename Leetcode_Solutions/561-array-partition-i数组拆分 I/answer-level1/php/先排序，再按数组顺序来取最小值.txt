
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function arrayPairSum($nums) {
        $num = 0;
        sort($nums);
        $count = count($nums);
        for($i=0;$i<$count;$i++){
            if($i % 2 == 0){
                $num = min($nums[$i],$nums[$i+1]) + $num;
            }
        }
        return $num;
    }
}