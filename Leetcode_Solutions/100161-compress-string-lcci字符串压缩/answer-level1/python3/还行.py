### 解题思路
此处撰写解题思路
思路：for循环 ，从1开始遍历 注意遍历到最后i==n-1的情况。
### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        n=len(S)
        if not S or n<0:
            return ""
        temp=S[0]
        count=1
        res=''
        for i in range(1,n):
            if temp!=S[i]:
                res+=temp+str(count)
                temp=S[i]
                count=1
            else:
                count+=1
            #注意收尾 
            if i==n-1:
                res += temp + str(count)
        return res if len(res)<n  and res!=''  else S
```