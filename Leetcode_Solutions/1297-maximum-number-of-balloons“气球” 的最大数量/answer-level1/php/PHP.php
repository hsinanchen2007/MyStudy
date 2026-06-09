时间复杂度： O(n)
空间复杂度： O(1)

```php
class Solution {

    /**
     * @param String $text
     * @return Integer
     */
    function maxNumberOfBalloons($text) {
        $hash = [
            'b' => 0,
            'a' => 0,
            'l' => 0,
            'o' => 0,
            'n' => 0
        ];

        for ($i = 0, $length = strlen($text); $i < $length; $i++) {
            if (isset($hash[$text[$i]])) {
                $hash[$text[$i]]++;
            }
        }

        $hash['l'] = (int) ($hash['l'] / 2);
        $hash['o'] = (int) ($hash['o'] / 2);

        $min = $hash['b'];

        foreach ($hash as $value) {
            $min < $value ?: $min = $value;
        }

        return $min;
    }
}
```