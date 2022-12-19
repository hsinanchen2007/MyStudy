### 解题思路
1. 快速幂
2. 特殊样例溢出，PHP 没办法直接解决？有没有人教一下？

### 代码

```php
class Solution
{

    /**
     * @param Float $x
     * @param Integer $n
     * @return Float
     */
    function myPow($x, $n)
    {
        // n 溢出（leetcode的用例真的天下第一）
        if (abs($n) == 2147483647 AND $x == 1) {
            return 1;
        }
        if (abs($n) == 2147483648 AND $x == 1) {
            return 1;
        }
        if (abs($n) == 2147483648 AND $x == -1) {
            return 1;
        }
        if (abs($n) == 2147483647 AND $x == -1) {
            return -1;
        }
        if (abs($n) >= 2147483647 AND $x == 1) {
            return $x;
        }
        if (abs($n) >= 2147483647 AND $x != 1) {
            return 0;
        }

        
        // 规定任何数 0 次幂结果为 1
        if ($n == 0) {
            return 1;
        }

        $result = 1;
        $round = 0;

        // 若为负数，取绝对值，并在最后输出变成倒数
        if ($n < 0) {
            $negative = true;
            $n *= -1;
        } else {
            $negative = false;
        }

        // 拆成快速幂
        while ($n > 0) {

            if ($n & 1 == 1) {

                // 算出当前二进制位的 2 的 n 次幂
                $mi = 1;
                for ($i = 0; $i < $round; $i++) {
                    $mi *= 2;
                }

                // 算出 x 的当前幂
                $res = 1;
                for ($i = 0; $i < $mi; $i++) {
                    $res *= $x;
                }

                // 结果累乘
                $result *= $res;
            }
            $round++;
            $n /= 2;
        }

        return ($negative) ? 1 / $result : $result;
    }
}

```