### 解题思路
常规解法

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function findLengthOfLCIS($nums) {
        $maxCount = $nowCount = 0;

        foreach ($nums as $i => $num) {
            if ($num > $nums[$i-1] ?? $nums[0]) {
                $nowCount ++;
            
                if ($nowCount > $maxCount) $maxCount = $nowCount;
            
            } else {
                $nowCount = 1;
            }
        }

        return $maxCount;
    }
}
```