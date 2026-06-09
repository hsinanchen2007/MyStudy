### 解题思路
借助in_array判断数组是否存在于当前循环值匹配的数,借助array_search 函数获得匹配数的键

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
   function twoSum($nums, $target)
    {
        foreach ($nums as $key => $value) {
            $i = $target - $value;
            if (in_array($i, $nums)) {
                $k = array_search($i, $nums);
                if ($k != $key) {
                    return [$key, $k];
                }
            }
        }
    }
}
```