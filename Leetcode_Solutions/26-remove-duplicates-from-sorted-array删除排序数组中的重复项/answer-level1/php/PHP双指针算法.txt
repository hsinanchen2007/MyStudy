### 解题思路
双指针算法的PHP实现
在所有 PHP 提交中击败了98.69%的用户
### 代码

```php
class Solution {

    /**
     * 双指针算法   
     * @param Integer[] $nums
     * @return Integer
     */
    function removeDuplicates(&$nums) {
        $a = 0;
        $b = 1;
        for($b = 1; $b < count($nums); $b++){
            if($nums[$a] != $nums[$b]) $nums[++$a] = $nums[$b];
        }
        // 按短指针截取指定长度的有效数组
        $nums = array_slice($nums, 0, $a + 1);
        return count($nums);
    }
}
```