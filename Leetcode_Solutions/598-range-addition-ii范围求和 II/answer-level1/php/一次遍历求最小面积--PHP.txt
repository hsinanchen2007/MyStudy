### 解题思路
此处撰写解题思路

### 性能
执行用时 :20 ms, 在所有 PHP 提交中击败了83.33%的用户
内存消耗 :23.1 MB, 在所有 PHP 提交中击败了100.00%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer $m
     * @param Integer $n
     * @param Integer[][] $ops
     * @return Integer
     */
    function maxCount($m, $n, $ops) {
        for ($i = 0; $i < count($ops); $i++) {
            $m = min($m, $ops[$i][0]);
            $n = min($n, $ops[$i][1]);
        }

        return $m * $n;
    }
}
```

### 参考
[https://leetcode-cn.com/problems/range-addition-ii/solution/fan-wei-qiu-he-ii-by-leetcode/](https://leetcode-cn.com/problems/range-addition-ii/solution/fan-wei-qiu-he-ii-by-leetcode/)