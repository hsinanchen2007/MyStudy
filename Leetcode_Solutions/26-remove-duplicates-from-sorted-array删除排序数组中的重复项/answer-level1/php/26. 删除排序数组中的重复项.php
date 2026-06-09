### 执行结果
**通过**
1. 执行用时 :36 ms， 在所有 PHP 提交中击败了15.59%的用户
2. 内存消耗 :16.7 MB, 在所有 PHP 提交中击败了95.53%的用户

### 解题思路
- 要求：原地修改，不使用额外数组空间
- 双指针法（慢指针 $i ：记录不重复元素指针；快指针 $j ：数组遍历指针）
- 当($nums[$i] != $nums[$j])时，将快指针的值赋值到慢指针下一位；当两者想等时候则跳过
- 注意：不要对数组进行unset()操作，会导致for循环遍历次数受到影响

### 代码

```php
class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function removeDuplicates(&$nums) {
        if(empty($nums)) return 0;

        $i = 0;
        for($j=1; $j<count($nums); $j++){
            if($nums[$i] != $nums[$j]){
                $i++;
                $nums[$i] = $nums[$j];
            }
        }
        // 按短指针截取指定长度的有效数组
        $nums = array_slice($nums, 0, $i+1);
        return count($nums);
    }
}
```