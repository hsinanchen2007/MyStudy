### 解题思路
此处撰写解题思路

方法一：迭代
### 代码

```php
class Solution {

    /**
     * @param Integer $n
     * @return Integer
     */
    function climbStairs($n) {
         if ($n == 1) {
            return 1;
        }
        $first = 1;
        $second = 2;
        for ($i = 3; $i <= $n; $i++) {
            $third = $first + $second;
            $first = $second;
            $second = $third;
        }

        return $second;
    }
}
```



方法二递归
思路最后一步台阶有2种选择，跨1步或者是跨2步，对应就是 f(n) = f(n-1)+f(n-2)
```
function climbStairs1($n)
{
    if ($n == 1) {
        return 1;
    }

    if ($n == 2) {
        return 2;
    }

    return climbStairs1($n - 1) + climbStairs1($n - 2);
}
```
