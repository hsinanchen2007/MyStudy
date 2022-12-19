### 解题思路
php内置方程

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Boolean
     */
    function containsDuplicate($nums) {
        $uni = array_unique($nums);
        return count($nums) != count($uni);
    }
}
```