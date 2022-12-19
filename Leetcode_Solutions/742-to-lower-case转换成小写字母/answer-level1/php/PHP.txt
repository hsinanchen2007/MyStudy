时间复杂度： O(n)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param String $str
     * @return String
     */
    function toLowerCase($str) {
        $hash = [
            'A' => 'a',
            'B' => 'b',
            'C' => 'c',
            'D' => 'd',
            'E' => 'e',
            'F' => 'f',
            'G' => 'g',
            'H' => 'h',
            'I' => 'i',
            'J' => 'j',
            'K' => 'k',
            'L' => 'l',
            'M' => 'm',
            'N' => 'n',
            'O' => 'o',
            'P' => 'p',
            'Q' => 'q',
            'R' => 'r',
            'S' => 's',
            'T' => 't',
            'U' => 'u',
            'V' => 'v',
            'W' => 'w',
            'X' => 'x',
            'Y' => 'y',
            'Z' => 'z'
        ];

        for ($i = 0, $length = strlen($str); $i < $length; $i++) {
            if (isset($hash[$str[$i]])) {
                $str[$i] = $hash[$str[$i]];
            }
        }

        return $str;
    }
}
```