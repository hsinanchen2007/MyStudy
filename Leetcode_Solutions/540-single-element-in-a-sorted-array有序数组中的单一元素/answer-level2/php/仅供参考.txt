class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function singleNonDuplicate($nums) {
        $arr = array();
        foreach($nums as $key=>$value)
        {
            if(array_key_exists($value,$arr))
            {
                $arr[$value]++;
            }
            else
            {
                $arr[$value] = 1;
            }
        }
        $a = array_flip($arr);
        return $a[1];
    }
}