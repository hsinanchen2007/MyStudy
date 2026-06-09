### 解题思路
如果一个数是3的幂次方，那么质因子只包含3，用3的幂次方最大的整数一定可以整除这个数。
整数范围内最大的3的幂次是3的19次幂，即1162261467

### 性能
执行用时 :56 ms, 在所有 php 提交中击败了66.67%的用户
内存消耗 :14.9 MB, 在所有 php 提交中击败了22.22%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer $n
     * @return Boolean
     */
    function isPowerOfThree($n) {
        return $n > 0 && 1162261467 % $n == 0;
    }
}
```

### 参考
[@kevinlining数论解决](https://leetcode-cn.com/problems/power-of-three/comments/4269)