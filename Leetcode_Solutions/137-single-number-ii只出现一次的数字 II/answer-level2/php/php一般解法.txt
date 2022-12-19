class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function singleNumber($nums) {
        $arr = array();
        for($i=0;$i<count($nums);$i++)
        {
            if(!array_key_exists($nums[$i],$arr))
            {
                $arr[$nums[$i]] = 1;
            }
            else
            {
                $arr[$nums[$i]]++;
            }
        }
        $arr = array_flip($arr);
        return $arr[1];
    }
}