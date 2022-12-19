![微信图片编辑_20191010101452.jpg](https://pic.leetcode-cn.com/e93e25807c256ef5d040dedec8e89120e7afb29360486937c24461c63361059d-%E5%BE%AE%E4%BF%A1%E5%9B%BE%E7%89%87%E7%BC%96%E8%BE%91_20191010101452.jpg)


class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function majorityElement($nums) {
        $num = array_count_values($nums);
        foreach($num as $key=>$value){
            if($value > count($nums)/2){
                return $key;
            }
        }
    }
}