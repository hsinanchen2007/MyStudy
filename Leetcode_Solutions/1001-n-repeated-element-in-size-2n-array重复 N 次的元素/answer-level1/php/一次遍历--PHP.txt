### 解题思路
遍历，检查当前元素跟下一个元素或者下下一个元素是否相等，相等就返回，否则就返回最后一个。

**注：因为遍历终止条件是count($A) - 2, 最后一个元素可能比对不到，故而返回最后一个元素。
**

### 性能
执行用时 :72 ms, 在所有 PHP 提交中击败了96.55%的用户
内存消耗 :16.7 MB, 在所有 PHP 提交中击败了10.00%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[] $A
     * @return Integer
     */
    function repeatedNTimes($A) {
        for ($i = 0; $i < count($A) - 2; $i++) {
            if ($A[$i] == $A[$i + 1] || $A[$i] == $A[$i + 2]) return $A[$i];
        }

        return $A[count($A) - 1];
    }
}
```

### 参考
[https://leetcode-cn.com/problems/n-repeated-element-in-size-2n-array/comments/10843](https://leetcode-cn.com/problems/n-repeated-element-in-size-2n-array/comments/10843)