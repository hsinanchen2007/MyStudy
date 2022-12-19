### 解题思路
异或、与、移位

### 性能
执行用时 :4 ms, 在所有 php 提交中击败了89.66%的用户
内存消耗 :14.9 MB, 在所有 php 提交中击败了14.29%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer $a
     * @param Integer $b
     * @return Integer
     */
    function getSum($a, $b) {
        while ($b != 0) {
            $carray = ($a & $b) << 1;
            $a = $a ^ $b;
            $b = $carray;
        }

        return $a;
    }
}
```

### 参考
[位运算详解以及在 Python 中需要的特殊处理](https://leetcode-cn.com/problems/sum-of-two-integers/solution/wei-yun-suan-xiang-jie-yi-ji-zai-python-zhong-xu-y/)