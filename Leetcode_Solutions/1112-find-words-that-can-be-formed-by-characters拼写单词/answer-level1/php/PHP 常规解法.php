按部就班的解法

```php
class Solution {

    /**
     * @param String[] $words
     * @param String $chars
     * @return Integer
     */
    function countCharacters($words, $chars) {
        $charCount = strlen($chars);
        if ($charCount == 0) return 0;
        $charHash = [];
        for ($i = 0; $i < $charCount; ++$i) {
            $char = substr($chars, $i, 1);
            if (!isset($charHash[$char])) $charHash[$char] = 0;
            $charHash[$char]++;
        }

        $result = 0;
        foreach ($words as $word) {
            if (strlen($word) > $charCount) continue;
            $wordLength = strlen($word);
            $tmpHash = $charHash;
            $result += $wordLength;
            for ($i = 0; $i < $wordLength; ++$i) {
                $char = substr($word, $i, 1);
                if (!isset($tmpHash[$char]) || $tmpHash[$char] == 0) {
                    $result -= $wordLength;
                    break;
                }
                $tmpHash[$char]--;
            }
        }

        return $result;
    }
}
```