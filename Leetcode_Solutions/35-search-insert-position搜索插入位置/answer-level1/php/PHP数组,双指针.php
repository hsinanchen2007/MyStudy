本题只需要遍历一次数组,严谨判断即可
```
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer
     */
    function searchInsert($nums, $target) {
        if (empty($nums)) {
            return 0;
        }
        $count = count($nums);
        for ($i=0;$i<$count;$i++) {
            $r = $i + 1;
            if ($nums[$i] == $target) {
                return $i;
            } elseif ($target<$nums[$i]) {
                return 0;
            } elseif (!isset($nums[$r])) {
                return $count;
            } elseif($nums[$r] == $target){
                return $r;
            } elseif ($target > $nums[$i] && $target < $nums[$r]) {
                return $r;
            }
        }
        return $count;
    }
}
```
