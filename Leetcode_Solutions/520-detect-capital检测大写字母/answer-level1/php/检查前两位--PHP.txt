### 解题思路
检查第一位，如果是小写，全是小写。如果是大写，检查第二位，第二位大写，全大写，否则全小写。

### 性能
执行用时 :12 ms, 在所有 PHP 提交中击败了28.57%的用户
内存消耗 :14.7 MB, 在所有 PHP 提交中击败了100.00%的用户

### 代码

```php
class Solution {

    /**
     * @param String $word
     * @return Boolean
     */
    function detectCapitalUse($word) {
        if ($word[0] >= 'a' && $word[0] <= 'z') {
            for ($i = 1; $i < strlen($word); $i++) {
                if ($word[$i] >= 'A' && $word[$i] <= 'Z') return false;
            }
        } else {
            if ($word[1] >= 'a' && $word[1] <= 'z') {
                for ($i = 2; $i < strlen($word); $i++) {
                    if ($word[$i] >= 'A' && $word[$i] <= 'Z') return false;
                }
            } else {
                for ($i = 2; $i < strlen($word); $i++) {
                    if ($word[$i] >= 'a' && $word[$i] <= 'z') return false;
                }
            }
        }

        return true;
    }
}
```