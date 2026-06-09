### 解题思路
要理解一个问题，每个台阶的走法是n-1个台阶+ n-2个台阶之和。 
动态规划的算法要点是 ，找到dp状态的定义，这里就是dp每个台阶的状态定义方法， dp方程，即将台阶问题转化为斐波拉契数列的问题。

### 代码

```php
class Solution {

    /**
     * @param Integer $n
     * @return Integer
     */
    function climbStairs($n) {
        $fib = [1, 1];
        for($i = 2; $i <= $n ; $i++){
            $fib[$i] = $fib[$i - 1] + $fib[$i - 2];
        }
        return $fib[$n];
    }
}
```