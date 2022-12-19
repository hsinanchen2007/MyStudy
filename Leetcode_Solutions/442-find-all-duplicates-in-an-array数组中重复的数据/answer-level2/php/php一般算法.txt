class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function findDuplicates($nums) {
        $arr = array();
        for($i=0;$i<count($nums);$i++)
        {
            if(array_key_exists($nums[$i],$arr))
            {
                $arr[$nums[$i]]++;
            }
            else
            {
                $arr[$nums[$i]] = 1;
            }
        }
        return array_keys(array_filter($arr,function($e){return $e == 2;}));
    }
}