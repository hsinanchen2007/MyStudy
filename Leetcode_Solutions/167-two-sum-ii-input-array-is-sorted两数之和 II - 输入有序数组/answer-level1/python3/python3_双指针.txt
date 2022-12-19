### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        length = len(numbers)
        pre = 0
        cur = length-1
        while pre < cur:
            if numbers[pre] + numbers[cur] == target:
                return [pre+1,cur+1]
            elif numbers[pre] + numbers[cur] > target:
                cur -= 1
            elif numbers[pre] + numbers[cur] < target:
                pre += 1
            else:
                return []
                

```