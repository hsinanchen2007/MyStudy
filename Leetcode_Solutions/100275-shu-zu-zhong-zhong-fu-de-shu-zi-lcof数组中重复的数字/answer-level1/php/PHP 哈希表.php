### 解题思路
最容易想到的解法。题解中有提到桶排序的，有时间再补。

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function findRepeatNumber($nums) {
        $hash = [];
        foreach ($nums as $num) {
            if (isset($hash[$num])) {
                return $num;
            }
            $hash[$num] = $num;
        }
    }
}
```