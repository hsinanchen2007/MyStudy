```
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        head, back = 0, len(numbers) - 1
        while head < back:
            if numbers[head] + numbers[back] == target: return [head+1, back+1]
            if numbers[head] + numbers[back] > target: 
                back -= 1
            else:
                head += 1
        return []
```
