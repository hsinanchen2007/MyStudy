### 解题思路
遍历每个字符，以当前字符为中心，往左右辐射，检查是否相等，直到不相等为止，记录最后相等的长度即以当前字符为中国女性的回文字符串的长度，根据这个长度，可以计算出这个回文串的开始和截止下标。下一个字符串为中心的长度如果大于之前的长度，就更新。遍历完后获取的长度就是最大长度。

### 算法
1. 初始化最长字符串的开始和截止下标都为0，即start = end = 0;
2. 遍历字符串，计算以当前字符串为中心的最长回文字符串的长度。（注意需要计算两次，第一次是一个字符串为中心, 如: abcba;第二次是以2个字符串为中心, 如: abccba）。
3. 如果以当前字符串为中心的长度大于之前的长度，就跟新start和end下标。
4. 遍历完后返回start和end之间的字符串。

### 性能
执行用时 :320 ms, 在所有 PHP 提交中击败了68.38%的用户
内存消耗 :14.9 MB, 在所有 PHP 提交中击败了80.91%的用户

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return String
     */
    public function longestPalindrome($s) {
        $len = strlen($s);
        if ($len < 2) return $s;

        $start = $end = 0;
        for ($i = 0; $i < $len; $i++) {
            // 奇数中心的长度
            $odd_len  = $this->getCenterLen($s, $i, $i);
            // 偶数中心的长度
            $even_len = $this->getCenterLen($s, $i, $i + 1);
            $max_len = max($odd_len, $even_len);
            if ($max_len > ($end - $start + 1)) {
                // 计算左下标的时候，长度需要-1，奇数其实不需要，偶数需要。这个地方不是特别好理解，画图有助于理解
                $start = $i - intval(($max_len - 1) / 2);
                $end = $i + intval($max_len / 2);
            }
        }

        return substr($s, $start, $end - $start + 1);
    }

    /**
     * @param  String $s
     * @param int $left 左指针
     * @param int $right 右指针
     * @return int
     */
    public function getCenterLen($s, $left, $right)
    {
        while ($left >= 0 && $right < strlen($s) && $s[$left] == $s[$right]) {
            $left--;
            $right++;
        }

        // 因为最后一次满足条件后，又执行了一次$left--和$right++，所以需要减去一位
        return $right - $left - 1;
    }
}
```

### 参考
[官方解题](https://leetcode-cn.com/problems/longest-palindromic-substring/solution/zui-chang-hui-wen-zi-chuan-by-leetcode/)