### 解题思路
遍历单词，检查是否在每行中。把单词和行字符拼接去重后长度不变，说明在。

### 性能
执行用时 :4 ms, 在所有 PHP 提交中击败了92.31%的用户
内存消耗 :15.1 MB, 在所有 PHP 提交中击败了100.00%的用户

### 代码

```php
class Solution {

    /**
     * @param String[] $words
     * @return String[]
     */
    function findWords($words) {
        $rows = [
            10 => 'qwertyuiop',
            9  => 'asdfghjkl',
            7  => 'zxcvbnm'
        ];

        $res = [];

        foreach ($words as $word) {
            foreach ($rows as $len => $row) {
                if ($len == count(array_unique(str_split($row . strtolower($word))))) {
                    $res[] = $word;
                    break;
                }
            }
        }

        return $res;
    }
}
```