```
class Solution {

    /**
     * @param String $target
     * @return Integer
     */
    function lengthOfLongestSubstring($target) {
        $temp = '';
        $max = 0;
        for ($i = 0; $i < strlen($target); $i++) {
            $len = strpos($temp, $target[$i]);
            if ($len === false) {
                $temp .= $target[$i];
            } else {
                $temp = substr($temp, $len + 1) . $target[$i];
            }
            $max = max(strlen($temp), $max);
        }
        return $max;
    }
}
```
