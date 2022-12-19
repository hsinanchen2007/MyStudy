### 解题思路
暴力循环遍历的就不贴代码了。

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target) {
        $flip = [];
        foreach ($nums as $key => $num) {
            $last = $target - $num;
            if (isset($flip[$last])) {
                return [$flip[$last], $key];
            }
            $flip[$num] = $key;
        }
    }
}
```