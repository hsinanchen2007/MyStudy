### 解题思路
典型的递归。

发现算法写多了，自然就不容易出错。

### 性能
执行用时 :192 ms, 在所有 PHP 提交中击败了33.87%的用户
内存消耗 :14.8 MB, 在所有 PHP 提交中击败了19.05%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer $N
     * @return Integer
     */
    function fib($N) {
        if ($N < 2) return $N;
        return $this->fib($N - 1) + $this->fib($N - 2);
    }
}
```