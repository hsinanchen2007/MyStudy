class Solution:
# APP1: brute force, nested loop. TLE

```
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        if not numbers or len(numbers) < 2:
            return [-1, -1]
        n = len(numbers)
        for i in range(n - 1):
            for j in range(i + 1, n):
                if numbers[i] + numbers[j] == target:
                    return [i + 1, j + 1]
        return [-1, -1]
```
    
# APP2: since it's sorted, loop through then binary search
# Time: O(nlogn), Space: O(1)

```
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        if not numbers or len(numbers) < 2:
            return [-1, -1]
        n = len(numbers)
        for i in range(n - 1):
            need = target - numbers[i]
            index = self.binary_search(numbers, i + 1, need)
            if index != -1:
                return [i + 1, index + 1]
        return [-1, -1]
    
    def binary_search(self, nums: List[int], begin: int, need: int) -> int:
        start, end = begin, len(nums) - 1
        while start + 1 < end:
            mid = start + (end - start) // 2
            if nums[mid] <= need:
                start = mid
            else:
                end = mid
        if nums[start] == need:
            return start
        if nums[end] == need:
            return end
        return -1
```
            
# APP3: Hashtable two passes
# Time: O(n), Space: O(n)

```
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        if not numbers or len(numbers) < 2:
            return [-1, -1]
        mapping = {}
        for index, num in enumerate(numbers):
            mapping[num] = index
        for index, num in enumerate(numbers):
            need = target - num
            if need in mapping and index != mapping[need]:
                return [index + 1, mapping[need] + 1]
        return [-1, -1]
```
        
# APP4: Hashtable one pass
# Time: O(n), Space: O(n)

```
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        if not numbers or len(numbers) < 2:
            return [-1, -1]
        mapping = {}
        for index, num in enumerate(numbers):
            if target - num in mapping:
                return [mapping[target - num] + 1, index + 1]
            mapping[num] = index
        return [-1, -1]
```
        
# APP5: since it's sorted, two pointers
# Time: O(n), Space: O(1):

```
    def twoSum(self, numbers: List[int], target: int) -> List[int]:
        if not numbers or len(numbers) < 2:
            return [-1, -1]
        start, end = 0, len(numbers) - 1
        while start < end:
            cur = numbers[start] + numbers[end]
            if cur == target:
                return [start + 1, end + 1]
            if cur < target:
                start += 1
            if cur > target:
                end -= 1
        return [-1, -1]
```
