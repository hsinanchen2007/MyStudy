### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        res=[]
        for i in range(2,target):
            a1=(2*target/i-i+1)/2
            if a1<=0:
                break
            if a1==int(a1):
                res.append([])
                for j in range(i):
                    res[-1].append(int(a1+j))
        return res[::-1]
```