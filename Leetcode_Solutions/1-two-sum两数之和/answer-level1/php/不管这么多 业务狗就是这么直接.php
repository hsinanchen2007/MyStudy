### 解题思路
此处撰写解题思路

### 代码

```php
class Solution
{

    /**
     * @param Integer[] $nums
     * @param Integer $target
     * @return Integer[]
     */
    function twoSum($nums, $target)
    {

        foreach ($nums as $key => $v) {
            $is_exists = $target - $v;
            foreach ($nums as $i => $num) {
                if ($i != 0 && $num == $is_exists && $i != $key) {
                    return [$key, $i];
                }
            }
        }
        return [0, 0];

    }
}
```