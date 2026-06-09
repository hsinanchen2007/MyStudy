### 解题思路
题目虽然简单，看如何更节省内存的实现了。

### 代码

```php
class Solution {

    /**
     * @param String $S
     * @return String
     */
    function toGoatLatin($S) {
        $suffix = 'a';
        $vowel = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U'];

        $words = explode(' ', $S);
        foreach ($words as &$word) {
            if (!in_array($word[0], $vowel)) {
                $word = substr($word, 1) . $word[0];
            }

            $word .= 'ma' . $suffix;
            $suffix .= 'a';
        }

        return implode(' ', $words);
    }
}
```

### 算法复杂度
- 时间复杂度: O(N)
- 空间复杂度: O(1)

### 参考
[https://leetcode-cn.com/problems/goat-latin/solution/python-shi-xian-by-jalan/](https://leetcode-cn.com/problems/goat-latin/solution/python-shi-xian-by-jalan/)