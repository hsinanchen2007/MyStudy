### 解题思路
暴力法

### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        a=[]
        for i in range(1,target):
            max1 = i
            for j in range(i+1,target+1):
                max1 += j
                if max1 > target:
                    break
                if max1 == target:
                    a.append(list(range(i,j + 1)))
        return a

```