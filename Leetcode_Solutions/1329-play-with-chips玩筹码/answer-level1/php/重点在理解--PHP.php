### 解题思路
把题目搞清楚，是解题的重点。很多人看了题解后恍然大悟就是计算奇偶，奇偶也不是那么容易想到的。

chips = [1,2,3]表示，位置1、2、3各有一个筹码，共3各筹码。
chips = [2,2,2,3,3]表示位置2有3各筹码，位置3有2个筹码。

### 性能
执行用时 :8 ms, 在所有 php 提交中击败了79.31%的用户
内存消耗 :15.2 MB, 在所有 php 提交中击败了100.00%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[] $chips
     * @return Integer
     */
    function minCostToMoveChips($chips) {
        $odd = $even = 0;
        foreach ($chips as $chip) {
            if ($chip % 2 == 0) {
                $even++;
            } else {
                $odd++;
            }
        }

        return min($odd, $even);
    }
}
```