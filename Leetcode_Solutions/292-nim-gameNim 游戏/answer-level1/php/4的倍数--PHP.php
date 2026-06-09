### 解题思路
找规律，你先手，只有是4的倍数你就输了。
4、8、12、16...

### 性能
执行用时 :0 ms, 在所有 php 提交中击败了100.00%的用户
内存消耗 :15 MB, 在所有 php 提交中击败了11.11%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer $n
     * @return Boolean
     */
    function canWinNim($n) {
        return ($n % 4) != 0;
    }
}
```