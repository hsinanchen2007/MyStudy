### 解题思路
1. 遍历一遍数组，统计数组中 0 的个数，并删除 0元素
2. 在数组末尾补 0

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return NULL
     */
    function moveZeroes(&$nums)
    {
        $zeroCount  = 0;
        $arrayCount = count($nums);
        for ($i = 0; $i < $arrayCount; ++ $i) {
            if ($nums[$i] == 0) {
                $zeroCount++;
                unset($nums[$i]);
            }
        }

        while ($zeroCount --) {
            $nums[] = 0;
        }
        return $nums;
    }
}
```