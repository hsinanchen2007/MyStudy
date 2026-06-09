遍历一次即可
```
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $val
     * @return Integer
     */
    function removeElement(&$nums, $val) {
        if (empty($nums)) {
            return 0;
        }
        $times = 0;
        $count = count($nums);
        for ($i=0; $i < $count; $i++) {
            if ($nums[$i] == $val) {
                unset($nums[$i]);
                continue;
            }
            $times++;
        }
        return $times;
    }
}
```
