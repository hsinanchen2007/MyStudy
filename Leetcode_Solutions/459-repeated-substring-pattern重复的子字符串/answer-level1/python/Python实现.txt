### 解题思路
最简单直接的算法就是将字符串s分成i等份（i >= 2)，判断每一等份的子字符串是否相同。当且仅当i存在时，返回true，否则返回false。算法的时间复杂度是O(N^2)。
优化算法：构造s+s，得到新的字符串ss，判断ss[1: ss.size()-1]中是否包含s，若包含，返回true，否则返回false。算法的时间复杂度是O(N).
下面介绍构造s+s方法的思路：
1）首先如果s由i个子串构成且i >= 2
i >= 2 ↔ 2i-i >= 2 ↔ 2i-2 >= i
故当2i-2个子串构成的字符串中包含i个子串构成的字符串时，i >= 2
2）如何构造2i-2个子串：
s由i个子串构成，则有s+s由2i个子串构成。
对s+s掐头去尾后，第一个和最后一个子串被破坏，则剩下2i-2个子串

### 代码

```python 算法1
class Solution(object):
    def repeatedSubstringPattern(self, s):
        """
        :type s: str
        :rtype: bool
        """
        n = len(s)
        if n <= 1: 
            return False
        for i in range(2, n+1):
            if n%i:       # 必须能被分成 i 等份
                continue
            count = n/i   # 每个子字符串的长度
            ss = s[:count]
            sign = True
            for j in range(1, i):
                if ss != s[count * j: count * (j+1)]:
                    sign = False
                    break
            if sign:
                break
        return sign
```

```python 算法2
class Solution(object):
    def repeatedSubstringPattern(self, s):
        """
        :type s: str
        :rtype: bool
        """
        ss = s+s
        if ss[1: len(ss)-1].find(s) != -1:
            return True
        return False
```