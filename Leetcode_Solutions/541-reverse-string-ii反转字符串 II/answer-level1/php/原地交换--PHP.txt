### 解题思路
以2k的步长遍历字符串，每次遍历的时候交换前k个元素。

### 性能
执行用时 :8 ms, 在所有 PHP 提交中击败了76.47%的用户
内存消耗 :15.2 MB, 在所有 PHP 提交中击败了50.00%的用户

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @param Integer $k
     * @return String
     */
    function reverseStr($s, $k) {
        for ($start = 0; $start < strlen($s); $start += 2 * $k) {
            $front = $start;
            $rear = min($start + $k - 1, strlen($s) - 1);
            while ($front < $rear) {
                $tmp = $s[$front];
                $s[$front++] = $s[$rear];
                $s[$rear--] = $tmp;
            }
        }

        return $s;
    }
}
```

### 参考
[官方解题：反转字符串 II](https://leetcode-cn.com/problems/reverse-string-ii/solution/fan-zhuan-zi-fu-chuan-ii-by-leetcode/)