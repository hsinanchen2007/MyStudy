### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function longestPalindrome($s) {
        $length = strlen($s);

        if ($length == 0) {
            return 0;
        }

        $arr = str_split($s);
        $arrCountValues = array_count_values($arr);
        $one = 0;
        $maxLen = 0;

        foreach ($arrCountValues as $value) {
            if ($value % 2) {
                $one = 1;
            }
            
            $maxLen += $value % 2 ? $value - 1 : $value;
        }

        return $maxLen + $one;
    }
}
```