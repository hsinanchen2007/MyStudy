### 解题思路
双指针，检查如果不是回文，去掉一个字符后在检查。

注意：左右指针实际不用相遇，即终止条件是$left < $right, $left <= $right也可以，只是没必要

### 性能
执行用时 :48 ms, 在所有 php 提交中击败了50.00%的用户
内存消耗 :15.2 MB 在所有 php 提交中击败了50.00%的用户

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Boolean
     */
    function validPalindrome($s) {
        for ($front = 0, $rear = strlen($s) - 1; $front < $rear; $front++, $rear--) {
            if ($s[$front] != $s[$rear]) {
                return $this->isPalindrome($s, $front + 1, $rear) OR $this->isPalindrome($s, $front, $rear - 1);
            }
        }

        return true;
    }

    public function isPalindrome($str, $left, $right)
    {
        while ($left < $right) {
            if ($str[$left] != $str[$right]) {
                return false;
            }
            $left++;
            $right--;
        }
        
        return true;
    }
}
```