这道题很简单,找出最大个数即可.但是需要注意很多细节.
```
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function findMaxConsecutiveOnes($nums) {
        if (empty($nums)) {
            return 0;
        }
        $count = count($nums);
        if ($count == 1) {
            return $nums[0] == 1 ? 1 : 0;
        }
        $num = 0;
        $list = [];
        for ($i=0;$i<$count;$i++) {
            if ($nums[$i] != 0) {
                $list[] = $nums[$i];
            } else {
                $num = max($num, count($list));
                $list = [];
            }
        }
        if ($list) {
            return max($num, count($list));
        }
        return $num;
    }
}
```
