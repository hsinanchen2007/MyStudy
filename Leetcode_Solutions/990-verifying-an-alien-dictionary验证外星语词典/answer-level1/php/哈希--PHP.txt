### 解题思路
把字母序列存在哈希中，记录索引。两两比较单词。

这种题接起来还是挺烦的，快不了。

### 性能
执行用时 :12 ms, 在所有 PHP 提交中击败了100.00%的用户
内存消耗 :14.8 MB, 在所有 PHP 提交中击败了100.00%的用户

### 代码

```php
class Solution {

    /**
     * @param String[] $words
     * @param String $order
     * @return Boolean
     */
    function isAlienSorted($words, $order) {
        $map = [];
        for ($i = 0; $i < strlen($order);$i++) {
            $map[$order[$i]] = $i;
        }

        for ($j = 1; $j < count($words); $j++) {
            if(!$this->compareWord($words[$j - 1], $words[$j], $map)) return false;
        }

        return true;
    }

    public function compareWord($word1, $word2, $map)
    {
        for ($i = 0; $i < strlen($word1) && $i < strlen($word2); $i++) {
            if ($word1[$i] != $word2[$i]) return $map[$word1[$i]] <= $map[$word2[$i]];
        }

        return strlen($word1) <= strlen($word2);
    }
}
```

### 算法复杂度
- 时间复杂度: O(N)
- 空间复杂度: O(N)

### 参考
[https://leetcode-cn.com/problems/verifying-an-alien-dictionary/solution/jie-ti-si-lu-he-godai-ma-by-laijinhang-20/](https://leetcode-cn.com/problems/verifying-an-alien-dictionary/solution/jie-ti-si-lu-he-godai-ma-by-laijinhang-20/)