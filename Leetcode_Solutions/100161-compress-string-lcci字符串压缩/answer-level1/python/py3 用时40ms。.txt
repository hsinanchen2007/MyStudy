### 解题思路
只需要记录上次存在的字符串，在答案字符串里面更新个数即可，最后合成一下答案字符串并且判断长度

### 代码

```python3
class Solution:
    def compressString(self, S: str) -> str:
        l=[]
        last=None
        for i in S:
            if last!=i:l.extend([i,1])
            else:l[-1]+=1
            last=i
        ans=''.join(map(str,l))
        return ans if len(ans)<len(S)else S
```