### 解题思路
这里需要使用两个 dict 双向绑定。

最开始只使用单向绑定，导致出错。 ab aa  和 ba aa 这样的样例过不了。

[详细通俗的思路分析，多解法](https://leetcode-cn.com/problems/isomorphic-strings/solution/) 第一种想法是只用一个 dict(), 判断 s 到 t 的转换是否正确，然后 t 到 s 的转换是否正确。

其推荐了第二种想法，找一个第三方的集合，使得 两者都对应到第三方集合。然后再判断。

一行python 代码：return [s.index(i) for i in s] == [t.index(i) for i in t]
但不推荐， O(n^2) 复杂度

### 代码

```python3
class Solution:
    def isIsomorphic(self, s: str, t: str) -> bool:
        n = len(s)
        if n == 0:
            return True
        D1 = dict()  # 需要双向绑定
        D2 = dict()  # 避免只是用一个dict, 可能会把两个字符映射到了同一个导致错误 ab aa
        for i in range(n):
            if s[i] in D1 and t[i] in D2:
                if D1[s[i]] != t[i] or D2[t[i]] != s[i]:
                    return False
            elif s[i] in D1 and t[i] not in D2:  
            # s[i] 已经和 D1[s[i]] 绑定，并且 D1[s[i]] 必然不是 t[i], 否则 t[i] 也已在 D2 中绑定
                return False
            elif s[i] not in D1 and t[i] in D2:
                return False
            else:
                D1[s[i]] = t[i]
                D2[t[i]] = s[i]
        return True

```