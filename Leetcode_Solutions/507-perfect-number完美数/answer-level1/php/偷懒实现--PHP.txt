### 解题思路
值得范围的完美数6, 28, 496, 8128, 33550336

### 性能
执行用时 :4 ms, 在所有 PHP 提交中击败了100.00%的用户
内存消耗 :14.8 MB, 在所有 PHP 提交中击败了20.00%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer $num
     * @return Boolean
     */
    function checkPerfectNumber($num) {
        return in_array($num, [6, 28, 496, 8128, 33550336]);
    }
}
```