### 解题思路
集合判断是否重复

### 代码

```python
class Solution:
    def __init__(self):
        self.s=set()
    def canReach(self, arr: List[int], start: int) -> bool:
        if start>=len(arr) or start<0:
            return False
        if start in self.s:
            return False
        self.s.add(start)
        if (start+arr[start]<len(arr) and arr[start+arr[start]]==0) or (start-arr[start]>-1 and arr[start-arr[start]]==0):
            return True
        return self.canReach(arr,start+arr[start]) or self.canReach(arr,start-arr[start])
```
![image.png](https://pic.leetcode-cn.com/6127829b5555d8971c83d8a3b6148b37ada547227a3f16529924fceb684689d0-image.png)

