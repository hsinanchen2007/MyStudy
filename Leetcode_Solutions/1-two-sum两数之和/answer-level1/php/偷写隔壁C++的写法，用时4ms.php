
```
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        $map = [];
        foreach($nums as $key => $num) {
            $a = $target - $num;
            if (isset($map[$a])) {
                return [$map[$a], $key];
            }
            $map[$num] = $key;
        }
    }
}
```