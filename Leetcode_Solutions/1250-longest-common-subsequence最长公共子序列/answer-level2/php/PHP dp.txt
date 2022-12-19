```php
class Solution {

    /**
     * @param String $text1
     * @param String $text2
     * @return Integer
     */
    function longestCommonSubsequence($text1, $text2) {
        $dp = [];
        for ($i = 0; $i < strlen($text1); $i++) {
            for ($j = 0; $j < strlen($text2); $j++) {
                if ($text1{$i} == $text2{$j}) {
                    $dp[$i][$j] = max(($dp[$i - 1][$j - 1] ?? 0) + 1, $dp[$i - 1][$j]?? 0, $dp[$i][$j - 1] ?? 0);
                } else {
                    $dp[$i][$j] = max($dp[$i - 1][$j] ?? 0, $dp[$i][$j - 1] ?? 0);
                }

            }
        }
        return $dp[strlen($text1) - 1][strlen($text2) - 1];
    }
}

```
