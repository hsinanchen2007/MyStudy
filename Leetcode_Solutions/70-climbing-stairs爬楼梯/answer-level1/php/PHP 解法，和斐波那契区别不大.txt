### 解题思路
此处撰写解题思路

### 代码

```php
class Solution {

    /**
     * @param Integer $n
     * @return Integer
     */
    function climbStairs($n) {
        // 感觉就是个斐波那契
        $count = 0;
        if ($n <= 0) {
            return $count;
        }

        $prev = 1;
        if ($n == 1) {
            return $prev;
        }

        $cur = 2;
        if ($n == 2) {
            return $cur;
        }

        $sum = $cur;
        for ($i = 3; $i <= $n; ++$i) {
            $sum = $prev + $cur;
            $prev = $cur;
            $cur = $sum;
        }

        return $sum;
    }
}
```