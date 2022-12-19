### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        i = 0
        j = len(numbers)-1
        while i<j:
            s = numbers[i]+numbers[j]
            if s>target:
                j -= 1
                while i<j and numbers[j] == numbers[j+1]:
                    j -= 1
            elif s<target:
                i += 1
                while i<j and numbers[i] == numbers[i-1]:
                    i += 1
            else:
                break
        if i < j:
            return [i+1,j+1]
        else:
            return []
```