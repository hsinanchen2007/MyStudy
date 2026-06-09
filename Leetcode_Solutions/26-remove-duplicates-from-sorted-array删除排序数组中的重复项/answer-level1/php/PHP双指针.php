双指针对于数组来说是很简单的操作方法,但是需要注意边界处理等问题
```
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function removeDuplicates(&$nums) {
        $count = count($nums);
        $out = 0;
        if (empty($nums)) {
            return $out;
        }
        for ($i=0; $i<$count; $i++) {
            if ($i==$count-1) {
                $out++;
                break;
            }
            $l = $i + 1;
            if ($nums[$i] == $nums[$l]) {
                unset($nums[$i]);
                continue;
            }
            $out++;
        }
        return $out;
    }
}
```
