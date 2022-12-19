### 解题思路
很容易就想到栈。实现起来也容易。

### 性能
执行用时 :32 ms, 在所有 php 提交中击败了73.68%的用户
内存消耗 :16 MB, 在所有 php 提交中击败了100.00%的用户

### 代码

```php
class Solution {

    /**
     * @param String $S
     * @return String
     */
    function removeDuplicates($S) {
        $stack = [$S[0]];
        for ($i = 1; $i < strlen($S); $i++) {
            if (end($stack) == $S[$i]) {
                array_pop($stack);
            } else {
                array_push($stack, $S[$i]);
            }
        }
        
        if (empty($stack)) return '';

        return implode('', $stack);
    }
}
```

### 说明
最后的字符串不需要反转, strrev();