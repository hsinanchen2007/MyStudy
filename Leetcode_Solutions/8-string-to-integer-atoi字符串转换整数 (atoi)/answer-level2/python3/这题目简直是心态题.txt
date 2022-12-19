### 解题思路
此处撰写解题思路
各种垃圾情况,不停的试
### 代码

```python3
class Solution:
    def myAtoi(self, str: str) -> int:
        ans=0
        tag=1
        fh=1
        bj=1
        for c in str:
            if tag and (c==' '):
                continue
            else:
                tag=0
            if tag==0 and c=='-':
                
                bj-=1
                if bj<0:return ans*fh
                fh=-1*fh
                continue
            if tag==0 and c=='+':
                
                bj-=1
                if bj<0:return ans*fh
                fh=1*fh
                continue
            
            if c.isdigit():
                bj-=1
                ans=ans*10+int(c)
            else:
                break
        ans=ans*fh
        if ans<-2147483648:ans=-2147483648
        if ans>2147483647:ans=2147483647
        return ans
                

```