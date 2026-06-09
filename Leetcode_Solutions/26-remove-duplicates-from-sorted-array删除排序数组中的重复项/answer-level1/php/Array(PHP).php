```
class Solution {
        
    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function removeDuplicates(&$nums) {
        if (empty($nums)) return 0;
        
        $p = 1;
        for ($q = 1; $q < count($nums); ++$q) {
            if ($nums[$q] != $nums[$q - 1]) {
                $nums[$p++] = $nums[$q];
            }
        }
        return $p;
    }
}
```
