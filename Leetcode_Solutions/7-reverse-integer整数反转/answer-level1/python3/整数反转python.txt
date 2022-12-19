### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def reverse(self, x: int) -> int:
        j=0
        if x>0:
            s=str(x)
            res=s[::-1]
        else:
            s=str(x)
            res=s[1:]
            res=res[::-1]
        for i in res:
            if i!=0:
                res=res[j:]
                j+=1
                break
        else:
            return 0
        if x>0:
            res=int(res)
        else:
            res=int('-'+res)
        if res>(2**31)-1 or res<-(2**31):
            return 0
        else:
            return res
```