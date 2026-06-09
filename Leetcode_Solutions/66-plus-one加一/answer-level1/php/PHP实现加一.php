思路：考虑末尾和开头是否为9；
末尾为9，则直接进一，更改为0；
开头为9，则直接增加数组长度1；数组开头更改为1，增加其0
```php []
class Solution {

    /**
     * @param Integer[] $digits
     * @return Integer[]
     */
    function plusOne($digits) {
        $count = count($digits);

        for ($i = $count - 1; $i >= 0; $i--) {
            if ($digits[$i] == 9) {
                if ($i == 0 && $digits[0] == 9) {
                    $digits[0] = 1;
                    $digits[$count] = 0;
                } else {
                    $digits[$i] = 0;
                }
            } else {
                $digits[$i]++;

                return $digits;
            }
        }

        return $digits;
    }
}
```

