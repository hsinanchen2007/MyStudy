```
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer[]
     */
    function findDisappearedNumbers($nums) {
        if (empty($nums)) {
            return [];
        }
        $count = count($nums);
        $hash = $out = [];
        for ($i=0;$i<$count;$i++) {
            $hash[$nums[$i]] = 1;
        }
        for ($i=1;$i<=$count;$i++) {
            if (!isset($hash[$i])) {
                $out[] = $i;
            }
        }
        return $out;
    }
}
```
