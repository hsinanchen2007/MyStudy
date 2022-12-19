class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function findMaxConsecutiveOnes($nums) {
        $str = implode($nums);
        $arr = explode('0',$str);
        $arr = array_filter($arr,function($e){return !empty($e);});
        return strlen(max($arr));
    }
}