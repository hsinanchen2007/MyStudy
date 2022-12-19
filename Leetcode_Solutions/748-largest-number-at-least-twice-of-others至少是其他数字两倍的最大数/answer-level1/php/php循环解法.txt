class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function dominantIndex($nums) {
        $max = max($nums);
        for($i=0;$i<count($nums);$i++)
        {
            if($nums[$i] != $max && $nums[$i]*2 > $max)
            {
                return -1;
            }
        }
        return array_search($max,$nums);
    }
}