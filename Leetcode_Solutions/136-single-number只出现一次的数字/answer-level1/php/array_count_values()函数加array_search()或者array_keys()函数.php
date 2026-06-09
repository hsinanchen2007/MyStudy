
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function singleNumber($nums) {
        // 计算数组元素出现个数
        $num = array_count_values($nums);
        // php数组根据值获取键名
        // $count = array_keys($num,1);
        // return $count[0];
        $count = array_search(1,$num);
        return $count;
    }
}