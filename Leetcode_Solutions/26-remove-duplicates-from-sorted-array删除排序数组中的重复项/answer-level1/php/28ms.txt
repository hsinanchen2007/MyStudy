### 解题思路
1. 已排序；2. 原地修改

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function removeDuplicates(&$nums) {
        // 1. 已排序，原地法
        $len = count($nums);
        if($len < 2) return $len;
        $tmp = $nums[0];
        for($i = 1; $i < $len; ++$i) {
            if($nums[$i] === $tmp) {
                unset($nums[$i]);
            } else {
                $tmp = $nums[$i];
            }
        }
        return count($nums);
    }
}
```