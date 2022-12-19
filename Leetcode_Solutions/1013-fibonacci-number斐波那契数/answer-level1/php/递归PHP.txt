### 解题思路
1. 找到分解公式
2. 写好跳出递归条件

### 代码

```php
class Solution {

    /**
     * @param Integer $N
     * @return Integer
     */
    function fib($N) {
        if ($N < 2) {
            return $N;
        }
        return $this->fib($N-1) + $this->fib($N-2);
    }
}
```