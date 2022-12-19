时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param Integer $n
     * @return String[]
     */
    function fizzBuzz($n) {
        $array = [];

        for ($i = 1; $i <= $n; $i++) {
            $array[$i] = '';
            if ($i % 3 == 0) {
                $array[$i] .= 'Fizz';
            }
            if ($i % 5 == 0) {
                $array[$i] .= 'Buzz';
            }
            if ($array[$i] == '') {
                $array[$i] = (string) $i;
            }
        }

        return $array;
    }
}
```