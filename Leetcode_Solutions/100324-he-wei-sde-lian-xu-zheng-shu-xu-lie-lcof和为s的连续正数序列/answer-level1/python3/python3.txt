### 解题思路
暴力遍历

### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        ans = []
        mid =  target // 2 + 1
        for start in range(1 , mid + 1):
            s = 0
            num = start
            tmp = []
            while s < target:
                s += num
                tmp.append(num)
                if s == target:
                    ans.append(tmp)
                num += 1
        return ans
```