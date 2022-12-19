### 解题思路
双指针，分别从收尾开始遍历，不是元音就跳过，直到分别找到第一个元音，然后交换。

### 性能
执行用时 :12 ms, 在所有 php 提交中击败了100.00%的用户
内存消耗 :15.3 MB, 在所有 php 提交中击败了28.57%的用户

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return String
     */
    function reverseVowels($s) {
        $vowels = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'];
        $front = 0;
        $rear = strlen($s) - 1;
        while ($front < $rear) {
            // 从左找到第一个元音
            while ($front < $rear && !in_array($s[$front], $vowels)) {
                $front++;
            }
            // 从右找第一个元音
            while ($front < $rear && !in_array($s[$rear], $vowels)) {
                $rear--;
            }
            
            // swap
            $tmp = $s[$front];
            $s[$front++] = $s[$rear];
            $s[$rear--] = $tmp;
        }

        return $s;
    }
}
```