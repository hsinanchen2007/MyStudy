## 代码

```python
class Solution:
    def repeatedSubstringPattern(self, s: str) -> bool:
        n = len(s)
        next = [-1] * n
        for i in range(1,n):
            j = next[i-1]
            while j >= 0 and s[j+1] != s[i]:
                j = next[j]
            if s[j+1] == s[i]:
                next[i] = j + 1
        return next[-1] >= 0 and n % (n - 1 - next[-1]) == 0
```

## 为什么使用kmp

对于一个重复的字符串，譬如

a b a b a b a b a b

他的next数组是（我这个next数组存的是数组的元素的index）

-1 -1 0 1 2 3 4 5 6 7 

观察到，除了第一个子字符串，其他子字符串的的next数组是连续的

n 为长度 减去 next[-1] + 1 就是一个子字符串的长度

n % 以上 == 0， 即成功验证

## 解释下kmp

Kmp的核心就是next数组（其实就是一个维护着位置的状态机）

以上面的例子

a b a b ？

在匹配 ? 的时候，因为 第一个 a b 和 第二个 a b相同，那么只需要比较 ？和第二个a了

写代码核心语句

```python
while j >= 0 and s[j+1] != s[i]:
                j = next[j]
```

这里是关键，和匹配到的 倒数第一个匹配 的下一个字符比对，对了，就成了
不成，和匹配到的 倒数第二个匹配 的下一个字符比对（此处的倒数第二个是通过倒数第一个next找到的）

![kmp.png](https://pic.leetcode-cn.com/da74fc01f9f063950b3315ed859fb0ee25532bb3f6482c81560dfd000a69c52d-kmp.png)


