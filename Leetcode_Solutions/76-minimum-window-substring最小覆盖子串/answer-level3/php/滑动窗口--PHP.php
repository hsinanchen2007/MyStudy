### 解题思路
滑动窗口、双指针

算法：
- 遍历t，把当前字符通过map来计数。
- 定义一个滑动窗口$window，$front和$rear分别指向窗口的首尾。
- 遍历s, 检查当前字符是否在t中，如果在，将当前字符加入到$window中并计数，当window中字符数量和t中相等，移动$front, 如果窗口长度比最小值小就替换。

### 性能
执行用时 :36 ms, 在所有 PHP 提交中击败了45.45%的用户
内存消耗 :15 MB, 在所有 PHP 提交中击败了100.00%的用户

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @param String $t
     * @return String
     */
    function minWindow($s, $t) {
        $start = $front = $rear = 0;
        $target = $window = [];
        $match = 0;
        $min_len = PHP_INT_MAX;

        for ($i = 0; $i < strlen($t); $i++) {
            $count = isset($target[$t[$i]]) ? $target[$t[$i]] : 0;
            $target[$t[$i]] = $count + 1;
        }

        while ($rear < strlen($s)) {
            $cr = $s[$rear];
            if ($target[$cr]) {
                $tmp = isset($window[$cr]) ? $window[$cr] : 0;
                $window[$cr] = $tmp + 1;
                if ($window[$cr] == $target[$cr]) {
                    $match++;
                }
            }
            $rear++;

            while ($match == count($target)) {
                if ($min_len > $rear - $front) {
                    $start = $front;
                    $min_len = $rear - $front;
                }

                $cf = $s[$front];
                if ($target[$cf]) {
                    $window[$cf]--;
                    if ($window[$cf] < $target[$cf]) {
                        $match--;
                    }
                }
                $front++;
            }
        }

        return $min_len == PHP_INT_MAX ? '' : substr($s, $start, $min_len);
    }
}
```

### 算法复杂度
- 时间复杂度 O(N)
- 空间复杂度 O(N)

### 参考
[https://leetcode-cn.com/problems/minimum-window-substring/solution/hua-dong-chuang-kou-suan-fa-tong-yong-si-xiang-by-/](https://leetcode-cn.com/problems/minimum-window-substring/solution/hua-dong-chuang-kou-suan-fa-tong-yong-si-xiang-by-/)