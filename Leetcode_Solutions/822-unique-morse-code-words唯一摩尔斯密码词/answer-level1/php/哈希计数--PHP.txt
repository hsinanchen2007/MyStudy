### 解题思路
此处撰写解题思路

### 性能
执行用时 :12 ms, 在所有 PHP 提交中击败了30.43%的用户
内存消耗 :15 MB, 在所有 PHP 提交中击败了8.70%的用户

### 代码

```php
class Solution {

    /**
     * @param String[] $words
     * @return Integer
     */
    function uniqueMorseRepresentations($words) {
        $morse = [".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."];

        foreach ($words as $word) {
            $tmp = '';
            for ($i = 0; $i < strlen($word); $i++) {
                $tmp .= $morse[ord($word[$i]) - ord('a')];
            }
            $map[$tmp] = true;
        }

        return count($map);
    }
}
```