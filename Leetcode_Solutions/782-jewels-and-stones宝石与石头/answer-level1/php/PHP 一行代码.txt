### 解题思路
简写了下，一行代码，性能比`substr_count` 低点。

执行用时 : `8 ms`, 在所有 `php` 提交中击败了 `71.93%` 的用户
内存消耗 : `14.8 MB` , 在所有 `php` 提交中击败了 `27.52%` 的用户

### 代码

```php
class Solution {

    /**
     * @param String $J
     * @param String $S
     * @return Integer
     */
    function numJewelsInStones($J, $S) {
        return count(array_intersect(str_split($S), str_split($J)));
    }
}
```