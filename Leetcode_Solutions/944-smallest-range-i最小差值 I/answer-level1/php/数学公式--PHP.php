### 解题思路
数学推理

注意：差值不可能小于0，最小是0

### 代码

```php
class Solution {

    /**
     * @param Integer[] $A
     * @param Integer $K
     * @return Integer
     */
    function smallestRangeI($A, $K) {
        $max = $min = $A[0];
        for ($i = 0; $i < count($A); $i++) {
            $max = max($max, $A[$i]);
            $min = min($min, $A[$i]);
        }

        return max(0, $max - $min - 2 * $K);
    }
}
```

### 算法复杂度
- 时间复杂度：O(N)
- 空间复杂度： O(1)

### 参考
[https://leetcode-cn.com/problems/smallest-range-i/solution/zui-xiao-chai-zhi-i-by-leetcode/](https://leetcode-cn.com/problems/smallest-range-i/solution/zui-xiao-chai-zhi-i-by-leetcode/)