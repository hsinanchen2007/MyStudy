## 思路:

思路一：排序（超时）暴力方法，每次选取和 `p`等长的字符串比较。

思路二：前缀和 + 哈希，我们按前缀统计字母的个数，这样便可方便求出和`p`等长的字符串是否一致。

思路三：滑动窗口，与前缀和思路差不多，只不过用数组比较是否相等。

## 代码:

思路一：

```python
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:  
        n = len(p)
        p = "".join(sorted(p))
        res = []
        for i in range(len(s) - n + 1):
            if "".join(sorted(s[i:i + n])) == p:
                res.append(i)
        return res
```

思路二：

```python
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        from collections import Counter
        n = len(p)
        p = Counter(p)
        dp = [0] * (len(s) + 1)
        dp[0] = Counter()
        res = []
        for i in range(1, len(s) + 1):
            dp[i] = dp[i - 1].copy()
            dp[i][s[i - 1]] += 1
            if i >= n and dp[i] - dp[i - n] == p:
                res.append(i - n)
        return res
```

思路三：

```python
class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        # 记录p, s字母个数
        p_count = [0] * 26
        s_count = [0] * 26
        res = []
        for a in p:
            p_count[ord(a) - 97] += 1
        left = 0
        for right in range(len(s)):
            # print(p_count, s_count)
            if right < len(p) - 1:
                s_count[ord(s[right]) - 97] += 1
                continue
            # 窗口加一个， 减一个，维护长度为len(p)的长度
            s_count[ord(s[right]) - 97] += 1
            if p_count == s_count:
                res.append(left)
            s_count[ord(s[left]) - 97] -= 1
            left += 1
        return res
```

