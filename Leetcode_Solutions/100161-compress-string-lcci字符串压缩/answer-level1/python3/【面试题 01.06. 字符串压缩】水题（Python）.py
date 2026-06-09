## 思路

这道题水的点在于，只要读懂题，按照题目描述写代码就行，完全不需要绕弯和技巧。只需要细心就行了～

我这里给S增加了一个字符"-"，减少特殊情况的逻辑判断。

## 代码


```python
class Solution:
    def compressString(self, S: str) -> str:
        S += '-'
        cnt, n, encoded = 1, len(S),  ""
        
        for i in range(1, n):
            if S[i] == S[i - 1]:
                cnt += 1
            else:
                encoded += S[i - 1] + str(cnt)
                cnt = 1

        return S[:-1] if len(encoded) >= n - 1 else encoded
```
**复杂度分析**
- 时间复杂度：$O(N)$
- 空间复杂度：$O(1)$

欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)