###思路
用1表示山峰左侧，-1表示山峰右侧，依次遍历

### 代码

```python3
class Solution:
    def validMountainArray(self, A: List[int]) -> bool:
        if len(A)<3:
            return False
        if A[1]>A[0]:
            pos=1
        else:
            return False
        for i in range(1,len(A)):
            if A[i]==A[i-1]:
                return False
            if A[i]>A[i-1] and pos==1:
                continue
            elif A[i]<A[i-1] and pos==1:
                pos=-1
            elif A[i]<A[i-1] and pos==-1:
                continue
            else:
                return False
        return pos==-1
```
![image.png](https://pic.leetcode-cn.com/f86fa4e1e26fc759a07ac4b7c69722d5c82f58a56c61f631f92a8a6bc9fddd7e-image.png)
