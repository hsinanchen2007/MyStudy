class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        $hash_list = array();
        foreach ($nums as $num_key => $num_value){
            $sub_value = $target - $num_value;
            if(isset($hash_list[$sub_value])){
                return array($num_key, $hash_list[$sub_value]);
            } else {
                $hash_list[$num_value] = $num_key;
            }
        }

    }
}