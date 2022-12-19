![image.png](https://pic.leetcode-cn.com/d029a61545477a771dcbeafbb934eb279d2d06646cfa06f0b457789b5e07950d-image.png)

只需要记录前两个扫描值的答案就可以了，连续两次出现0就剪枝。

```
class Solution:
    def numDecodings(self, s: str) -> int:
        n=len(s)
        if n==0:
            return 0
        ans=0
        if s[0]!='0':
            ans=1
        if n==1:
            return ans
        ans2=ans
        if s[1]=='0':
            ans=0
        if '10'<=s[:2]<='26':
            ans+=1
        if n==2:
            return ans
        ans1=ans
        for i in range(2,n):
            ans=0
            if s[i]!='0':
                ans=ans1
            if '10'<=s[i-1:i+1]<='26':
                ans+=ans2
            if ans==0 and ans1==0:
                return 0
            ans2,ans1=ans1,ans
        return ans
```
