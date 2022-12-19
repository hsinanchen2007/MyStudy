class Solution {

    /**
     * @param Integer[] $arr
     * @return NULL
     */
    function duplicateZeros(&$arr) {
        $count1 = count($arr);
        for($i=0;$i<count($arr);$i++)
        {
            if($arr[$i] == 0)
            {
                $arr[$i] = '0,0';
            }
        }
        $arr = explode(',',implode(',',$arr));
        foreach($arr as $key=>$value)
        {
            if($key >= $count1)
            {
                unset($arr[$key]);
            }
        }
    }
}