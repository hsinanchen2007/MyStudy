### 解题思路
遍历数组，记录下遍历过的内容，检查是否存在。

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Boolean
     */
    function containsDuplicate($nums) {
        $map = [];
        for ($i = 0; $i < count($nums); $i++) {
            if ($map[$nums[$i]]) {
                return true;
            }
            $map[$nums[$i]] = true;
        }

        return false;
    }
}
```