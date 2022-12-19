# 最大公约数

## 思路

实际上这题本质就是求解最大公约数。

- 从左向右遍历str1和str2
- 如果str1和str2不等，直接返回“”
- 最终返回str1和str2长度的最大公约数即可


## 代码

```python
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        i = j = 0
        m, n = len(str1), len(str2)
        while i < m or j < n:
            if str1[i % m] != str2[j % n]: return ""
            i += 1
            j += 1
        def gcd(a, b):
            return a if b == 0 else gcd(b, a % b)
        return str1[:gcd(m, n)]
```

**复杂度分析**
- 时间复杂度：$O(max(m, n))$
- 空间复杂度：$O(log(min(m,n)))$

# 简化最大公约数

实际上，我们简化代码，即`如果str1 + str2 != str2 + str1`那么直接返回“”即可

```python
class Solution:
    def gcdOfStrings(self, str1: str, str2: str) -> str:
        m, n = len(str1), len(str2)
        if str1 + str2 != str2 + str1: return ""
        def gcd(a, b):
            return a if b == 0 else gcd(b, a % b)
        return str1[:gcd(m, n)]
```

**复杂度分析**
- 时间复杂度：$O(m + n)$
- 空间复杂度：$O(m + n)$

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)
