### 解题思路
遍历，实时计数行和宽度

### 性能
执行用时 :8 ms, 在所有 PHP 提交中击败了42.86%的用户
内存消耗 :15 MB, 在所有 PHP 提交中击败了75.00%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer[] $widths
     * @param String $S
     * @return Integer[]
     */
    function numberOfLines($widths, $S) {
        $line = 1;
        $width = 0;
        for ($i = 0; $i < strlen($S); $i++) {
            $width += $widths[ord($S[$i]) - ord('a')];
            if ($width > 100) {
                $line++;
                $width = $widths[ord($S[$i]) - ord('a')];
            }
        }

        return [$line, $width];
    }
}
```

### 算法复杂度
- 时间复杂度: O(N)
- 空间复杂度: O(N)

### 参考
[https://leetcode-cn.com/problems/number-of-lines-to-write-string/solution/xie-zi-fu-chuan-xu-yao-de-xing-shu-by-leetcode/
](https://leetcode-cn.com/problems/number-of-lines-to-write-string/solution/xie-zi-fu-chuan-xu-yao-de-xing-shu-by-leetcode/)