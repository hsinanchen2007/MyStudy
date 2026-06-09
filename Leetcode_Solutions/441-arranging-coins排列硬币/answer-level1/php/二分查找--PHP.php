### 解题思路
等差数列求和公式
S = ka1 + k(k - 1)d / 2

这里把阶梯行看成等差数列，d = 1, a1 = 1.
因为中间值mid表示索引，所以k = m + 1

思考：n个硬币，n >= 2的时候，比如不能形成n行，是不是可以优化尾指针。

### 性能
执行用时 :12 ms, 在所有 php 提交中击败了78.38%的用户
内存消耗 :14.9 MB, 在所有 php 提交中击败了7.14%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer $n
     * @return Integer
     */
    function arrangeCoins($n) {
        $front = 0;
        $rear = $n - 1;
        while ($front <= $rear) {
            $mid = intval(($front + $rear) / 2);
            $sum = (($mid + 1) * ($mid + 2)) /2;
            if ($sum > $n) {
                $rear = $mid - 1;
            } elseif ($sum < $n) {
                $front = $mid + 1;
            } else {
                return $mid + 1;
            }
        }

        return $front;
    }
}
```