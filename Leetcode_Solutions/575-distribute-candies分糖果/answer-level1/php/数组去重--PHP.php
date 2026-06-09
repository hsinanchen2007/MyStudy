### 解题思路
因为是偶数个，并且平均分配，所以最大种类就是总数的1/2，去重之后就是全部种类n，如果小于1/2，就是n.

### 性能
执行用时 :432 ms, 在所有 PHP 提交中击败了10.34%的用户
内存消耗 :16.3 MB, 在所有 PHP 提交中击败了100.00%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[] $candies
     * @return Integer
     */
    function distributeCandies($candies) {
        return min(count(array_unique($candies)), intval(count($candies) / 2));
    }
}
```