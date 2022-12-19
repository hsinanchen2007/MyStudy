class Solution {

    /**
     * 
     * @param Integer[] $nums
     * @return Integer
     */
    function totalHammingDistance($nums) {
        if (count($nums) <2) return 0;
        $ret = 0;
        $cnt = [];
        foreach ($nums as $v) {
            $i = 0;
            while($v > 0) {
                $cnt[$i] += $v&1; 
                $v = $v >> 1;
                $i++;
            }
        }

        $cn = count($nums);
        foreach ($cnt as $v) {
            $ret = $ret + $v * ($cn - $v);
        }
        return $ret;
    }
}