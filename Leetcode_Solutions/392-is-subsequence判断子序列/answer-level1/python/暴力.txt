### 解题思路
![QQ截图20200328223040.png](https://pic.leetcode-cn.com/787bd11d35446be66bfd2d68ff4573c354489cbd9e477a02b960986c14ece56d-QQ%E6%88%AA%E5%9B%BE20200328223040.png)

今天做“零和一”那个问题没做出来，心情不好，不做题了，写两个easy水一水
### 代码

```python3
class Solution:
    def isSubsequence(self, s: str, t: str) -> bool:
        i=0
        j=0
        while i<len(s) and j<len(t):
            if s[i]==t[j]:
                i+=1
                j+=1
            else:
                j+=1
    
        return i==len(s)
```