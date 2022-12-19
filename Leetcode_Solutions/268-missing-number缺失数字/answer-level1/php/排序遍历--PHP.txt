### 解题思路
排序，然后遍历

注意：[0]返回1, [0, 1]返回2, 最后如果不存在返回序列最后一个元素 + 1, 不应该返回-1么

### 性能
执行用时 :56 ms, 在所有 php 提交中击败了50.62%的用户
内存消耗 :16.3 MB, 在所有 php 提交中击败了7.81%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function missingNumber($nums) {
        sort($nums);

        for ($i = 0; $i < count($nums); $i++) {
            if ($i != $nums[$i]) {
                return $i;
            }
        }

        return $nums[count($nums) - 1] + 1;
    }
}
```