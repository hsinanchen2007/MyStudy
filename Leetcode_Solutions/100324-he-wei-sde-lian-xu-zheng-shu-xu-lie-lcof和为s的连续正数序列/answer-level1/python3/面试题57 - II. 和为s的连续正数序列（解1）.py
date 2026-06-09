### 解题思路
滑动窗口求和

### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        ans = []
        i = 1
        j = 2
        end = target // 2
        while i <= end and j <= end+1:
            num = (i + j) * (j - i + 1)/2
            # print(i,j,num)
            if num == target:
                ans.append([k for k in range(i, j+1)])
                i += 1
            elif num > target:
                i += 1
            else:
                j += 1
        return ans
```