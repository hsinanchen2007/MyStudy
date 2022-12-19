### 解题思路
一次遍历，定义快慢两个指针i, j，都指向当前元素，如果当前元素为0，移动快指针i, 慢指针不移动; 如果当前元素不为0就把i指向的元素赋值给j指向的位置，j移动一位。最好末尾补0。

### 性能
执行用时 :12 ms, 在所有 PHP 提交中击败了89.89%的用户
内存消耗 :16.3 MB, 在所有 PHP 提交中击败了15.83%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return NULL
     */
    function moveZeroes(&$nums) {
        for ($i = 0, $j = 0; $i < count($nums); $i++) {
            if ($nums[$i] != 0) $nums[$j++] = $nums[$i];
        }

        while ($j < count($nums)) {
            $nums[$j++] = 0;
        }
    }
}
```

### 算法复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(1)

### 参考
[https://leetcode-cn.com/problems/move-zeroes/comments/5381](https://leetcode-cn.com/problems/move-zeroes/comments/5381)