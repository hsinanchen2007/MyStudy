
```
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function lengthOfLongestSubstring($s) {
        $sCount = strlen($s);
        $tmpCount = 0;
        $maxCount = 0;
        $tmpStr = '';
        for ($i = 0; $i < $sCount; $i++) {
            if ($tmpStr) {
                $striStr = strpos($tmpStr, $s[$i]);
                if ($striStr === false) {
                    $tmpStr .= $s[$i];
                    $tmpCount++;
                    $maxCount = $maxCount >= $tmpCount ? $maxCount : $tmpCount;
                } elseif ($striStr >= 0) {
                    $tmpStr = substr($tmpStr, $striStr + 1);
                    $tmpStr .= $s[$i];
                    $tmpCount = strlen($tmpStr);
                    $maxCount = $maxCount >= $tmpCount ? $maxCount : $tmpCount;
                } else {
                    $tmpStr = '';
                    $maxCount = $maxCount >= $tmpCount ? $maxCount : $tmpCount;
                    $tmpCount = 0;
                }
            } else {
                $tmpStr = $s[0];
                $tmpCount++;
                if ($i == 0) {
                    $maxCount = $tmpCount;
                }
            }
        }
        return $maxCount;
    }
}
```
