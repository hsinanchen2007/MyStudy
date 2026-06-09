### 解题思路
使用map来定义窗口，字符为key, value为下标。i, j分别为窗口的开始和截止下标。遍历发现有重复字符，计算一次i。

### 性能
执行用时 :44 ms, 在所有 PHP 提交中击败了30.80%的用户
内存消耗 :14.9 MB, 在所有 PHP 提交中击败了34.60%的用户

### 代码

```php
class Solution {

    /**
     * @param String $s
     * @return Integer
     */
    function lengthOfLongestSubstring($s) {
        $map = [];
        $len = 0;
        for ($i = 0, $j = 0; $j < strlen($s); $j++) {
            if (in_array($s[$j], array_keys($map))) {
                $i = max($map[$s[$j]], $i);
            }
            $len = max($len, $j - $i + 1);
            $map[$s[$j]] = $j + 1;
        }

        return $len;
    }
}
```