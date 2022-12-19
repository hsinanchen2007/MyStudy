时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param String $address
     * @return String
     */
    function defangIPaddr($address) {
        $ip = '';

        for ($i = 0, $length = strlen($address); $i < $length; $i++) {
            $ip .= $address[$i] == '.' ? '[.]' : $address[$i];
        }

        return $ip;
    }
}
```