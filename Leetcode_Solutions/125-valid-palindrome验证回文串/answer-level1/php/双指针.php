### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function isPalindrome($s) {
        $front = 0;
        $rear = strlen($s) - 1;
        $s = strtolower($s);
        while ($front < $rear) {
            // 注意这里是while, 不是if
            while ($front < $rear && !ctype_alnum($s[$front])) $front++;
            while ($front < $rear && !ctype_alnum($s[$rear])) $rear--;
            if ($s[$front] != $s[$rear]) {
                return false;
            }
            $front++;
            $rear--;
        }

        return true;
    }
}
```