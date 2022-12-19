
**一个简单的例子**

已知字符串`S1='abcc'`，其最长无重复子串是`'abc'`，问字符串`S2='abccd'`的最长无重复子串长度是什么？

S1结尾加上`'d'`之后，最长无重复子串有两种可能的来源：
1. 最长无重复子串包含新增的`'d'`，即`'cd'`
2. 最长无重复子串不包含新增的`'d'`，即`S1`的最长无重复子串`'abc'`

比较`'cd'`与`'abc'`，`len('abc')>len('cd')`，所以`S2`的最长无重复子串依然是`'abc'`

**推导状态转移方程**

根据例子的思路推广至一般的情况：
给出一个字符串`Si`，已知它的最长子串长度为`Li`，如果在`Si`的末尾追加一个字符`C`，即`Si+1=Si+C`，那么`Si+1`的最长子串是多少？

很容易想到：

`lengthOfLongestSubString(Si+1)=max(Li,len(C结尾的无重复子串))`

**思路的具体实现**

根据状态转移方程，轻松得到代码，因为查找新增字符结尾的无重复子串长度是向左搜索，所以暂且把这个过程取名叫`find_left`
```
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        for i in range(0, len(s)):
            length = max(length, find_left(s, i))
        return length
```

接下来，求以s为结尾的无重复子串长度，这就非常容易了
```
def find_left(s, i):
    tmp_str = s[i]
    j = i - 1
    while j >= 0 and s[j] not in tmp_str:
        tmp_str += s[j]
        j -= 1
    return len(tmp_str)
```

最后考虑一些特殊情况
```
if s == '':
    return 0
if len(s) == 1:
    return 1
```

**完整的代码**

```
class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        if s == '':
            return 0
        if len(s) == 1:
            return 1

        def find_left(s, i):
            tmp_str = s[i]
            j = i - 1
            while j >= 0 and s[j] not in tmp_str:
                tmp_str += s[j]
                j -= 1
            return len(tmp_str)
        length = 0
        for i in range(0, len(s)):
            length = max(length, find_left(s, i))
        return length
```

