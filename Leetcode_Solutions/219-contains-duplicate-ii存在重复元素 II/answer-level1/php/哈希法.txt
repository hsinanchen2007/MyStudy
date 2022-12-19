### 解题思路
采用哈希，key是遍历过的值，value为index, 注意index可能为0，需要用isset判断是否存在$map[$nums[$i]]

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $k
     * @return Boolean
     */
    function containsNearbyDuplicate($nums, $k) {
        $map = [];

        for ($i = 0; $i < count($nums); $i++) {
            if (isset($map[$nums[$i]]) && $i - $map[$nums[$i]] <= $k) {
                return true;
            }
            $map[$nums[$i]] = $i;
        }

        return false;
    }
}
```