### 解题思路
此处撰写解题思路
字符串处理还是python好使
### 代码

```python
class Solution(object):
    def licenseKeyFormatting(self, S, K):
        """
        :type S: str
        :type K: int
        :rtype: str
        """
        S = "".join(S.split('-'))
        res = []
        for i in range(len(S),0,-K):
            start = max(i-K,0)
            res.append(S[start:i])
        res.reverse()
        return "-".join(res).upper()
```