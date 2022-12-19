思路：先把数组排序，在和之前的数组作比较，记录同一位置值不同的数组下标。当数组不为空时，用最大下标减去最小下标加上一即是

class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function findUnsortedSubarray($nums) {
        $count = count($nums);
        $new = $nums;
        sort($new);
        $child = [];
        for($i=0;$i<$count;$i++){
           if($new[$i] != $nums[$i]){
              $child[] = $i;
           }
        }
        return empty($child)?0:max($child)-min($child)+1;
    }
}