### 解题思路
数组及字符串转换

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return String
     */
    function reverseWords($s) {
        if (!$s) return $s;
        $wordList = explode(' ', trim($s));
        $i = count($wordList) - 1;
        $reserverList = [];
        while ($i >= 0) {
            if ($wordList[$i]) {
                $reserverList[] = $wordList[$i];
            }
            $i --;
        }

        return implode(' ', $reserverList);
    }
}
```