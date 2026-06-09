class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function firstMissingPositive($nums) {
        $min_nums = min($nums);
        $max_nums = max($nums);
        if($min_nums > 1 || $max_nums < 0) return 1;
        
        sort($nums);

        foreach($nums as $v) {
            if($v < 0) {
                continue;
            }
            for($i = 1; $i <= $v; $i++) {
                if(!in_array($i, $nums)) return $i;

            }
 
        }

        return $max_nums+1;
       
        
    }
}