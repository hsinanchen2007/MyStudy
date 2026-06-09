### 解题思路
设置一个start记录当前计数的字符，当下一个字符不等于它的时候，计算字符重复的长度，如果长度大于3，就写入答案

### 代码

```python3
class Solution:
    def largeGroupPositions(self, S: str) -> List[List[int]]:
        res=[]
        n=len(S)
        start=0
        for i in range(n):
            if S[i]!=S[start]:
                if i-start>=3:
                    res.append([start,i-1])
                start=i
        if n-start>=3:
            res.append([start,n-1])
        return res
            
```