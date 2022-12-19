### 解题思路
遍历数组，把0删除，然后追加到数组末尾。unset数组元素，下标并不会变。

### 性能
执行用时 :16 ms, 在所有 php 提交中击败了64.49%的用户
内存消耗 :16.1 MB, 在所有 php 提交中击败了17.24%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return NULL
     */
    function moveZeroes(&$nums) {
        foreach ($nums as $k => $num) {
            if ($num == 0) {
                unset($nums[$k]);
                $nums[] = 0;
            }
        }
    }
}
```