- hash表:
```python
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        hashTable = {}
        for i in range(len(numbers)):
            if hashTable.get(target - numbers[i]) is not None:
                return hashTable[target - numbers[i]] + 1, i + 1
            hashTable[numbers[i]] = i
```
- 二分查找:
```python
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        for i in range(len(numbers)):
            ans = target - numbers[i]
            k = len(numbers) - 1
            j = i + 1
            while j <= k:
                mid = (j + k) // 2
                if numbers[mid] == ans:
                    return i + 1, mid + 1
                elif numbers[mid] < ans:
                    j = mid + 1
                else:
                    k = mid - 1
```
- 双指针:
```python
class Solution:
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        i = 0
        j = len(numbers) - 1
        while i < j:
            _sum = numbers[i] + numbers[j]
            if target == _sum:
                return i + 1, j + 1
            elif target < _sum:
                j -= 1
            else:
                i += 1
```