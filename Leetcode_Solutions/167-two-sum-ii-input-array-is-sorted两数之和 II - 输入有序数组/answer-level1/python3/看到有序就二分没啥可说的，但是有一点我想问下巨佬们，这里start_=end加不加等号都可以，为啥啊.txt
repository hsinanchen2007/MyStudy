### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        if not numbers:
            return [-1,-1]
        
        start = 0
        end = len(numbers) -1

        while start <= end:
            sumVal = numbers[start] + numbers[end]
            if target == sumVal:
                return [start+1,end+1]
            elif target > sumVal:
                start+=1
            else:
                end -= 1
        return [-1,-1]
                


```