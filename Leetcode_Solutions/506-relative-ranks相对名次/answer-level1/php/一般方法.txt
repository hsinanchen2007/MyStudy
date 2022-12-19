class Solution {

    /**
     * @param Integer[] $nums
     * @return String[]
     */
    function findRelativeRanks($nums) {
        $num = $nums;
        rsort($num);
        $g = $num[0];
        $s = $num[1];
        $b = $num[2];
        foreach($nums as $key=>&$value)
        {
            if($value == $g)
            {
                $value = "Gold Medal";
            }
            elseif($value == $s)
            {
                $value = "Silver Medal";
            }
            elseif($value == $b)
            {
                $value = "Bronze Medal";
            }
            else
            {
                $value = "".(array_keys($num,$value)[0]+1)."";
            }
        }
        return $nums;
    }
}