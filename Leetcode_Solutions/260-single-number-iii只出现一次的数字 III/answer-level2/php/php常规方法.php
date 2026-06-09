class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function singleNumber($nums) {
        $num = array();
        for($i = 0;$i<count($nums);$i++)
        {
            if(array_key_exists($nums[$i],$num))
            {
                $num[$nums[$i]]++;
            }
            else
            {
                $num[$nums[$i]] = 1;
            }
        }
        $number = array_filter($num,function($e){return $e==1;});
        $key = array_keys($number);
        return $key;
    }
}