### 解题思路
快慢指针

### 性能
执行用时 :192 ms, 在所有 php 提交中击败了5.71%的用户
内存消耗 :17.3 MB, 在所有 php 提交中击败了14.29%的用户

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @param String $t
     * @return Boolean
     */
    function isSubsequence($s, $t) {
        $ps = $pt = 0;
        while ($ps <= strlen($s) && $pt <= strlen($t)) {
            if ($s[$ps] == $t[$pt]) {
                $ps++;
            }
            $pt++;
        }

        return !isset($s[$ps]);
    }
}
```