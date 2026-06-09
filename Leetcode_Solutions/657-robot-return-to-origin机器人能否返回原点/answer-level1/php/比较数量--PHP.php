### 解题思路
上下的数量和左右的数量都相等即可，很直观想到的。

### 性能
执行用时 :8 ms, 在所有 PHP 提交中击败了100.00%的用户
内存消耗 :14.9 MB, 在所有 PHP 提交中击败了60.00%的用户

### 代码

```php
class Solution {

    /**
     * @param String $moves
     * @return Boolean
     */
    function judgeCircle($moves) {
        return substr_count($moves, 'U') == substr_count($moves, 'D') && substr_count($moves, 'L') == substr_count($moves, 'R');
    }
}
```