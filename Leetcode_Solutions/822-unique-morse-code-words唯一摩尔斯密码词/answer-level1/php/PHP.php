时间复杂度： O(n)
空间复杂度： O(n)

```php
class Solution {

    /**
     * @param String[] $words
     * @return Integer
     */
    function uniqueMorseRepresentations($words) {
        $hash = [
            "a" => ".-",
            "b" => "-...",
            "c" => "-.-.",
            "d" => "-..",
            "e" => ".",
            "f" => "..-.",
            "g" => "--.",
            "h" => "....",
            "i" => "..",
            "j" => ".---",
            "k" => "-.-",
            "l" => ".-..",
            "m" => "--",
            "n" => "-.",
            "o" => "---",
            "p" => ".--.",
            "q" => "--.-",
            "r" => ".-.",
            "s" => "...",
            "t" => "-",
            "u" => "..-",
            "v" => "...-",
            "w" => ".--",
            "x" => "-..-",
            "y" => "-.--",
            "z" => "--.."
        ];
        $array = [];

        foreach ($words as $value) {
            $key = '';
            for ($i = 0, $length = strlen($value); $i < $length; $i++) {
                $key .= $hash[$value[$i]];
            }
            $array[$key] = '';
        }

        return count($array);
    }
}
```