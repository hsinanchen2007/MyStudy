### 解题思路
转成二进制字符串，把字符为1的位置存起来，遍历计算最大差距即可。

### 性能
执行用时 :8 ms, 在所有 PHP 提交中击败了66.67%的用户
内存消耗 :14.7 MB, 在所有 PHP 提交中击败了66.67%的用户

### 代码

```php
class Solution {

    /**
     * @param Integer $N
     * @return Integer
     */
    function binaryGap($N) {
        $bin = decbin($N);
        $indexs = [];
        for ($i = 0; $i < strlen($bin); $i++) {
            if ($bin[$i] == '1') $indexs[] = $i;
        }

        $ans = 0;
        for ($j = 0; $j < count($indexs); $j++) {
            if (($indexs[$j + 1] - $indexs[$j]) > $ans) $ans = $indexs[$j + 1] - $indexs[$j];
        }

        return $ans;
    }
}
```

### 算法复杂度
- 时间复杂度：O(N)
- 空间复杂度: O(N)

### 参考
[https://leetcode-cn.com/problems/binary-gap/solution/er-jin-zhi-jian-ju-by-leetcode/](https://leetcode-cn.com/problems/binary-gap/solution/er-jin-zhi-jian-ju-by-leetcode/)