### 解题思路

多种情况都考虑一下，写得比较麻烦，但是好懂

### 代码

```php
class Solution {

    /**
     * @param Integer[] $digits
     * @return Integer[]
     */
    function plusOne($digits) {
        $length = count($digits);
        $digits[$length - 1] += 1;
        for ($i = $length - 1; $i > 0; --$i) {
            if ($digits[$i] >= 10) {
                $digits[$i] -= 10;
                $digits[$i - 1] += 1;
            }
        }

        if ($digits[0] >= 10) {
            $digits[0] -= 10;
            array_unshift($digits, 1);
        }
        return $digits;
    }
}
```