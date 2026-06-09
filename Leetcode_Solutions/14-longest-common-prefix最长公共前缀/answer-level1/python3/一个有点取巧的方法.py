



### 解题思路
![C2Y~BNS@HP7@QF2)~S0CTJ2.png](https://pic.leetcode-cn.com/4c4af5149cbd841e58ff8d807c3ebf761b8ddf33648ae071f0a86ff041df4df4-C2Y~BNS@HP7@QF2\)~S0CTJ2.png)
取一个最长的和一个最短的比比。
本身是有漏洞的，比如:"abcd","abaa","abce"三个同长度的，取了"abcd"和"abce"返回"abc"，明显错误。
但是能过。

### 代码

```python3
class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs: return ("")
        mins,maxs=min((strs)),max((strs))
        for i in range(min(len(mins),len(maxs))):
            if(mins[i]!=maxs[i]):return mins[:i]
        return mins
```