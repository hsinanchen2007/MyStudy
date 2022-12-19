### 解题思路
按空格分隔，然后遍历反转单个单词，再拼接。怎么简单怎么来。

### 性能
执行用时 :8 ms, 在所有 PHP 提交中击败了95.35%的用户
内存消耗 :15.2 MB, 在所有 PHP 提交中击败了27.78%的用户

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return String
     */
    function reverseWords($s) {
        $words = explode(' ', $s);
        $res = '';
        foreach ($words as $index => $word) {
            if ($index != 0) $res .= ' ';
            $res .= strrev($word);
        }

        return $res;
    }
}
```