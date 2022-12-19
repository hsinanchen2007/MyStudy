### 解题思路
打卡

### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        ans = []
        for i in range(1,int(target/2)+1):
            sum = i
            j = i+1
            while sum < target:
                sum += j
                j += 1
            if sum == target:
                ans.append(list(range(i,j)))
        return ans
```