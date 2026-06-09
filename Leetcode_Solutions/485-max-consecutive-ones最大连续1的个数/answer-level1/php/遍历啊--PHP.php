### 解题思路
遍历哈

### 性能
执行用时 :112 ms, 在所有 PHP 提交中击败了96.88%的用户
内存消耗 :16.1 MB, 在所有 PHP 提交中击败了9.09%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function findMaxConsecutiveOnes($nums) {
        $count = $max_count = 0;
        foreach ($nums as $num) {
            if ($num == 1) {
                $count++;
            } else {
                if ($count > $max_count) $max_count = $count; 
                $count = 0;
            }
        }

        if ($count > $max_count) $max_count = $count; 

        return $max_count;
    }
}
```