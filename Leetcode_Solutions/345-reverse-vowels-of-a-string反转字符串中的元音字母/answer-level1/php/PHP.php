时间复杂度： O(n)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param String $s
     * @return String
     */
    function reverseVowels($s) {
        $hash = [
            'a' => '',
            'A' => '',
            'e' => '',
            'E' => '',
            'i' => '',
            'I' => '',
            'o' => '',
            'O' => '',
            'u' => '',
            'U' => ''
        ];

        $l = 0;
        $r = strlen($s) - 1;

        while ($l < $r) {
            if (!isset($hash[$s[$l]])) {
                $l++;
                continue;
            }
            if (!isset($hash[$s[$r]])) {
                $r--;
                continue;
            }
            $tmp = $s[$l];
            $s[$l] = $s[$r];
            $s[$r] = $tmp;
            $l++;
            $r--;
        }

        return $s;
    }
}
```