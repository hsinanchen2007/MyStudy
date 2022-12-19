### 解题思路
双指针，首尾同时扫描并交换

### 性能
执行用时 :60 ms, 在所有 php 提交中击败了74.09%的用户
内存消耗 :35.4 MB, 在所有 php 提交中击败了35.11%的用户

### 代码

```php
class Solution {

    /**
     * @param String[] $s
     * @return NULL
     */
    function reverseString(&$s) {
        $front = 0;
        $rear = count($s) - 1;
        while ($front < $rear) {
            $tmp = $s[$front];
            $s[$front++] = $s[$rear];
            $s[$rear--] = $tmp;
        }
    }
}
```