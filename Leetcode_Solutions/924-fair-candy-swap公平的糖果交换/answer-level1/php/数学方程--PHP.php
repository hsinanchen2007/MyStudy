### 解题思路
参考：[https://leetcode-cn.com/problems/fair-candy-swap/solution/gong-ping-de-tang-guo-jiao-huan-by-leetcode/](https://leetcode-cn.com/problems/fair-candy-swap/solution/gong-ping-de-tang-guo-jiao-huan-by-leetcode/)

### 代码

```php
class Solution {

    /**
     * @param Integer[] $A
     * @param Integer[] $B
     * @return Integer[]
     */
    function fairCandySwap($A, $B) {
        $delta = intval((array_sum($A) - array_sum($B)) / 2);
        foreach ($A as $val) {
            if (in_array($val - $delta, $B)) {
                return [$val, $val - $delta];
            }
        }
    }
}
```