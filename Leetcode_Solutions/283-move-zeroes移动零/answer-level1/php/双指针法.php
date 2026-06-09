### 解题思路
双指针，fast 用来遍历数组，slow 表示最后一个 0 的下标（初始时不一定）

1. 当 fast 遇到 0 时，fast++, slow 不变
2. 当 fast 不是 0 时，如果 slow 是 0 且 slow<fast, 交换 fast,slow 两元素。此时 slow 非零，slow++

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return NULL
     */
    function moveZeroes(&$nums) {
        $len = count($nums);
        if ($len <= 1) {
            return;
        }

        $slow = 0;
        for ($fast = 0; $fast < $len; ++$fast) {
            if ($nums[$fast] != 0) {
                if ($slow < $fast && $nums[$slow] == 0) {
                    $nums[$slow] = $nums[$fast];
                    $nums[$fast] = 0;
                }
                $slow++;
            }
        }
    }
}
```