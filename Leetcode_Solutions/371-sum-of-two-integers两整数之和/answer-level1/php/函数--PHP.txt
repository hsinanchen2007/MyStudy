### 解题思路
array_sum

### 性能
执行用时 :8 ms, 在所有 php 提交中击败了44.83%的用户
内存消耗 :14.9 MB, 在所有 php 提交中击败了14.29%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer $a
     * @param Integer $b
     * @return Integer
     */
    function getSum($a, $b) {
        return array_sum([$a, $b]);
    }
}
```