class Solution:
# APP1: nested loop get all combination of two numbers
# Time: O(n^2), Space: O(1)

```
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        if not nums or len(nums) < 2:
            return [-1, -1]
        for i in range(len(nums) - 1):
            for j in range(i + 1, len(nums)):
                if nums[i] + nums[j] == target:
                    return [i, j]
        return [-1, -1]
```

# APP2: sort the array for (num, index), use two pointers to find target
# Time: O(nlgn), Space: O(n)

```
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        if not nums or len(nums) < 2:
            return [-1, -1]
        new_nums = []
        for index, num in enumerate(nums):
            new_nums.append((num, index))
        # new_nums.sort(key = lambda num: (num[0], num[1])
        new_nums.sort()
        left, right = 0, len(nums) - 1
        while left < right:
            cur_sum = new_nums[left][0] + new_nums[right][0]
            if cur_sum == target:
                return [min(new_nums[left][1], new_nums[right][1]), max(new_nums[left][1], new_nums[right][1])]
            if cur_sum < target:
                left += 1
            if cur_sum > target:
                right -= 1
        return [-1, -1]
```
    
# APP3: loop through array, use binary search to find target - nums[i]
# Time: O(nlgn), Space: O(1)
 
```
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        if not nums or len(nums) < 2:
            return [-1, -1]
        new_nums = []
        for index, num in enumerate(nums):
            new_nums.append((num, index))
        # new_nums.sort(key = lambda num: (num[0], num[1])
        new_nums.sort()
        n = len(new_nums)
        for i in range(n - 1):
            index = self.find_index(target - new_nums[i][0], new_nums, i + 1)
            if index != -1:
                return [min(new_nums[i][1], index), max(new_nums[i][1], index)]
        return [-1, -1]
    
    def find_index(self, target, nums, start):
        left, right = start, len(nums) - 1
        while left + 1 < right:
            mid = left + (right - left) // 2
            if nums[mid][0] <= target:
                left = mid
            else:
                right = mid
        if nums[left][0] == target:
            return nums[left][1]
        if nums[right][0] == target:
            return nums[right][1]
        return -1
```

# APP4: first pass: use hashtable {num: index}, second pass: find target - nums[i]
# Time: O(n), Space: O(n)

```
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        if not nums or len(nums) < 2:
            return [-1, -1]
        mapping = {}
        for index, num in enumerate(nums):
            mapping[num] = index
        for index, num in enumerate(nums):
            lookup = target - num
            if lookup in mapping and mapping[lookup] != index:
                return [index, mapping[lookup]]
        return [-1, -1]
```
        
        
# APP5: one pass, store and find target - nums[i] same time
# Time: O(n), Space: O(n)

```
   def twoSum(self, nums: List[int], target: int) -> List[int]:
        if not nums or len(nums) < 2:
            return [-1, -1]
        mapping = {}
        for index, num in enumerate(nums):
            if target - num in mapping:
                return [mapping[target - num], index]
            mapping[num] = index
        return [-1, -1]
```
        