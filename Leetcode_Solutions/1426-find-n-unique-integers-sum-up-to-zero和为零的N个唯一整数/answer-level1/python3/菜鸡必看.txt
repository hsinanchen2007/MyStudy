### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def sumZero(self, n: int) -> List[int]:
        res=[] if n%2 ==0 else [0]
        if n>=2 :
            for i in range(1,n//2+1):
                res+=[-i]+[i]
        return res
```