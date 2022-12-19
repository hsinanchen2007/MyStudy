![image.png](https://pic.leetcode-cn.com/b01ef5e5874e48f2eada786a782ff47fb6a6cc1b965b2ed8f05caf56b8aa8ef3-image.png)


```
class Solution:
    def countAndSay(self, n: int) -> str:
        ans='1'
        for i in range(1,n):
            tmp=''
            m=len(ans)
            dig=ans[0]
            count=1
            for j in range(1,m):
                if ans[j]==dig:
                    count+=1
                else:
                    tmp+=str(count)+dig
                    dig=ans[j]
                    count=1
            ans=tmp+str(count)+dig
        return ans
```
