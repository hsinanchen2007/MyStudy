### 解题思路
sort

### 性能
执行用时 :92 ms, 在所有 PHP 提交中击败了61.36%的用户
内存消耗 :17.9 MB, 在所有 PHP 提交中击败了17.24%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[] $A
     * @return Integer[]
     */
    function sortedSquares($A) {
        foreach ($A as &$item) {
            $item = $item * $item;
        }

        sort($A);
        return $A;
    }
}
```