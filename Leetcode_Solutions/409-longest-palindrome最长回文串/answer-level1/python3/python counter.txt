1）首先跑出每个字符的个数。
2）遍历字符。两种情况
    1偶数肯定对称，直接加入到答案里。
    2奇数的字符减一（不能只取最长的）加到答案里。

3）返回答案。注意如果存在过奇数，还需加一（此奇数在最中间位置）。

```
class Solution:
    def longestPalindrome(self, s: str) -> int:
        
        res=0
        hasodd=False
        dic=collections.Counter(s)
        
        for i in dic.values():
            if i % 2==0:
                res+=i
            else:
                hasodd=True
                res+=i-1
        
        return res if not hasodd else res+1
```
