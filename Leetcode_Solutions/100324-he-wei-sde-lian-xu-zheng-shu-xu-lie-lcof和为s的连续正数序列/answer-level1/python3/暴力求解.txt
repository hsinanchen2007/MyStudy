### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def findContinuousSequence(self, target: int) -> List[List[int]]:
        num = 0
        temp = 1
        result = []
        while temp <= (target / 2):

            mid_re = []
            num=0
            num += temp
            low, high = temp, temp
            mid_re.append(low)
            while num < target:
                high += 1
                num += high
                mid_re.append(high)
            temp += 1
            if num == target:
                result.append(mid_re)
        return result






```