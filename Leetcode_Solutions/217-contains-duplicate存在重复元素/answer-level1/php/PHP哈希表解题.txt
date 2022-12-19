```
class Solution {

    /**
     * @param Integer[] $nums
     * @return Boolean
     */
    function containsDuplicate($nums) {
        $hash = [];
        $count = count($nums);
        for ($i=0;$i<$count;$i++) {
            if (isset($hash[$nums[$i]])) {
                return true;
            }
            $hash[$nums[$i]] = 1;
        }
        return false;
    }
}
```
