### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def numTimesAllBlue(self, light: List[int]) -> int:
      sum1 = 0
      max1 = 0 
      for i in range(len(light)):
        max1 = max(max1,light[i])
        if i+1 == max1:
          sum1 += 1
      return sum1
```