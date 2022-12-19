### 解题思路
如果直接遍历，性能比较低。这里采用折半的办法，减少遍历次数。

假如$x = 2
如果$n是偶数，$n = 4, 折半的序号依次为4, 2, 1, 折叠了一次。
如果$n是奇数，$n = 5, 折半的序号依次为5, 2, 1。

最后一次始终是1。

### 性能
执行用时 :4 ms, 在所有 PHP 提交中击败了98.67%的用户
内存消耗 :15.2 MB, 在所有 PHP 提交中击败了40.58%的用户

### 代码

```php
class Solution {

    /**
     * @param Float $x
     * @param Integer $n
     * @return Float
     */
    function myPow($x, $n) {
        $res = 1;
        for ($i = $n; $i != 0; $i = intval($i / 2)) {
            if ($i % 2 != 0) $res *= $x;

            $x *= $x;
        }

        return $n < 0 ? 1 / $res : $res;
    }
}
```

### 算法复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(N)

### 参考
[https://www.cnblogs.com/grandyang/p/4606334.html](https://www.cnblogs.com/grandyang/p/4606334.html)
[https://leetcode-cn.com/problems/powx-n/comments/10689](https://leetcode-cn.com/problems/powx-n/comments/10689)