
```
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        $arr = [];
        foreach($nums as $key => $value) {
            $diff = $target - $value;
            if (array_key_exists($diff,$arr)) {
                return [$key,$arr[$diff]];
            }
            $arr[$value] = $key;
        }
    }
}
```
