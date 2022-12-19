### 解题思路
每位都在(2, 5, 6, 9, 0, 1, 8)内，至少一位在(2, 5, 6, 9)内。

检查是否是好数，用递归也蛮有意义。

### 性能
执行用时 :80 ms, 在所有 PHP 提交中击败了81.25%的用户
内存消耗 :14.8 MB, 在所有 PHP 提交中击败了80.00%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer $N
     * @return Integer
     */
    function rotatedDigits($N) {
        $count = 0;
        for ($i = 1; $i <= $N; $i++) {
            if ($this->good($i)) $count++;
        }

        return $count;
    }

    // 检查一个数是否是好数
    public function good($num)
    {
        $flag = false;
        $str = strval($num);
        for ($i = 0; $i < strlen($str); $i++) {
            if (!in_array($str[$i], ['2', '5', '6', '9', '0', '1', '8'])) {
                return false;
            }
            if (in_array($str[$i], ['2', '5', '6', '9'])) {
                $flag = true;
            } 
        }

        return $flag;
    }
}
```

### 算法复杂度
- 时间复杂度：O(N)
- 空间复杂度: O(N)

### 参考
[https://leetcode-cn.com/problems/rotated-digits/comments/7432](https://leetcode-cn.com/problems/rotated-digits/comments/7432)
[https://leetcode-cn.com/problems/rotated-digits/solution/xuan-zhuan-shu-zi-by-leetcode/](https://leetcode-cn.com/problems/rotated-digits/solution/xuan-zhuan-shu-zi-by-leetcode/)