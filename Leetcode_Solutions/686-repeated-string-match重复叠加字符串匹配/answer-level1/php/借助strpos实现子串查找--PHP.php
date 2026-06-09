### 解题思路
B如果是A的子串，A的长度必须大于等于B。如果A长度大于B后，在重复一次A如果还没有找到子串，那么重复多少次都找不到。

注意：
0、计数器$count从1开始，A自身算是重复了一次。
1、重复代码不是$repeatA .= $repeatA;

### 性能
执行用时 :144 ms, 在所有 php 提交中击败了66.67%的用户
内存消耗 :14.9 MB, 在所有 php 提交中击败了100.00%的用户

### 代码

```php
class Solution {

    /**
     * @param String $A
     * @param String $B
     * @return Integer
     */
    function repeatedStringMatch($A, $B) {
        $count = 1;
        $repeatA = $A;
        while (strlen($repeatA) < strlen($B)) {
            $count++;
            $repeatA .= $A;
        }
        
        if (strpos($repeatA, $B) !== false) {
            return $count;
        }

        $repeatA .= $A;
        if (strpos($repeatA, $B) !== false) {
            return ++$count;
        }

        return -1;
    }
}
```