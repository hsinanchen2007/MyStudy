class Solution {

    /**
     * @param Integer[] $nums
     * @return String
     */
    function largestNumber($nums) {
        for ($i=0;$i<count($nums)-1;$i++) {
            for ($j=0;$j<count($nums)-$i-1;$j++) {
                if ((int)($nums[$j].$nums[$j+1]) < (int)($nums[$j+1].$nums[$j])) {
                    $tmp = $nums[$j];
                    $nums[$j] = $nums[$j+1];
                    $nums[$j+1] = $tmp;
                } 
            }
        }
        $return = implode('',$nums);
        if ($return == '0') {
            $return = "0";
        }
        return $return;
    }
}

$nums = [3,30,34,5,9];
$solution = new Solution();
echo $solution->largestNumber($nums);