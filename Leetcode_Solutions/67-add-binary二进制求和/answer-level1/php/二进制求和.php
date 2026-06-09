### 解题思路
位与位相加，超过超过2则进一位

### 代码

```php
class Solution {

    /**
     * @param String $a
     * @param String $b
     * @return String
     */
    function addBinary($a, $b)
    {
        $up = 0;
        $i = strlen($a) - 1;
        $j = strlen($b) - 1;
        $new = '';

        $a = str_split($a);
        $b = str_split($b);
        while (isset($a[$i]) && isset($b[$j])) {
            $site = ($a[$i] + $b[$j] + $up) % 2;
            $up = $a[$i] + $b[$j] + $up >= 2 ? '1' : '0';
            $new = $site . $new;
            $i--;
            $j--;
        }

        if ($i >= 0) {
            for ($i; $i >= 0; $i--) {
                $site = ($a[$i] + $up) % 2;
                $up = $a[$i] + $up >= 2 ? '1' : '0';
                $new = $site . $new;
            }

        } else if ($j >= 0) {
            for ($j; $j >= 0; $j--) {
                $site = ($b[$j] + $up) % 2;
                $up = $b[$j] + $up >= 2 ? '1' : '0';
                $new = $site . $new;
            }
        }
        
        if ($up == 1) {
            $new = $up . $new;
        }
        return $new;
    }
}
```