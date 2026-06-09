### 解题思路
先列出所有的偶数，在列出所有的奇数，这样也可以。

### 性能
执行用时 :196 ms, 在所有 PHP 提交中击败了20.75%的用户
内存消耗 :16.2 MB, 在所有 PHP 提交中击败了8.00%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[] $A
     * @return Integer[]
     */
    function sortArrayByParity($A) {
        $queue = [];
        for ($i = 0; $i < count($A); $i++) {
            if ($A[$i] % 2 == 0) {
                array_unshift($queue, $A[$i]);
            } else {
                array_push($queue, $A[$i]);
            }
        }

        return $queue;
    }
}
```

### 参考
[python的这个解法没弄明白](https://leetcode-cn.com/problems/sort-array-by-parity/comments/2697)