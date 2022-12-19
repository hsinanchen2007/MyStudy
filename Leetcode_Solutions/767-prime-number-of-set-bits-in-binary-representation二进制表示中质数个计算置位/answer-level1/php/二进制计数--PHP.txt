### 解题思路
L，R 最大为 10^6，转换为二进制，有20位，最多有20个计算质位。检查这些计算质位那些是质数，最快的方法就是判断是否在20以内的质数列表中[2, 3, 5, 7, 11, 13, 17, 19]

### 性能
执行用时 :176 ms, 在所有 PHP 提交中击败了75.00%的用户
内存消耗 :14.8 MB, 在所有 PHP 提交中击败了100.00%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer $L
     * @param Integer $R
     * @return Integer
     */
    function countPrimeSetBits($L, $R) {
        $primes = [2, 3, 5, 7, 11, 13, 17, 19];
        $count = 0;
        for ($i = $L; $i <= $R; $i++) {
            $tmp = substr_count(decbin($i), '1');
            if (in_array($tmp, $primes)) $count++;
        }

        return $count;
    }
}
```

### 参考
[https://leetcode-cn.com/problems/prime-number-of-set-bits-in-binary-representation/comments/108408](https://leetcode-cn.com/problems/prime-number-of-set-bits-in-binary-representation/comments/108408)