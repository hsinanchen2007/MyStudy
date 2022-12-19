### 解题思路
分两次遍历，第一个遍历把字母押入栈中，第二次遍历遇到字母从栈顶弹出一个元素，否则使用当前字符。

**PHP竟然没有检查是否是字母的函数。**

### 代码

```php
class Solution {

    /**
     * @param String $S
     * @return String
     */
    function reverseOnlyLetters($S) {
        $stack = [];
        $res = '';
        for ($i = 0; $i < strlen($S); $i++) {
            if ($this->isLetter($S[$i])) array_push($stack, $S[$i]);
        }

        for ($i = 0; $i < strlen($S); $i++) {
            if ($this->isLetter($S[$i])) $res .= array_pop($stack);
            else $res .= $S[$i];
        }

        return $res;
    }

    /**
     * @param string $char
     * @return boolean
     */
    public function isLetter($char)
    {
        if (($char >= 'a' && $char <= 'z') || ($char >= 'A' && $char <= 'Z')) return true;

        return false;
    }
}
```

### 算法复杂度
- 时间复杂度: O(N)
- 空间复杂度: O(N)

### 参考
[leetcode官方解题](https://leetcode-cn.com/problems/reverse-only-letters/solution/jin-jin-fan-zhuan-zi-mu-by-leetcode/)