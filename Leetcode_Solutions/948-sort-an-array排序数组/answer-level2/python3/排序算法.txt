快速排序：
```python3
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:

        def partition(nums, p, r):
            i = p
            for j in range(p, r):
                if nums[j] < nums[r]:
                    nums[i], nums[j] = nums[j], nums[i]
                    i += 1
            nums[i], nums[r] = nums[r], nums[i]
            return i
                
        def quicksort(nums, p, r):
            if p >= r:return 
            q = partition(nums, p, r)
            quicksort(nums, p, q - 1)
            quicksort(nums, q + 1, r)
        
        n = len(nums)
        quicksort(nums, 0, n - 1)
        return nums

```


归并排序：
```
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:

        def merge(nums, p, mid, r):
            temp = []
            left, right = p, mid + 1
            
            while left <= mid and right <= r:
                if nums[left] <= nums[right]: 
                    temp += [nums[left]]
                    left += 1
                else:
                    temp += [nums[right]]
                    right += 1
            if left <= mid:temp += nums[left:mid+1]
            elif right <= r: temp += nums[right:r+1]
            nums[p:r+1] = temp

        def sort(nums, p, r):
            if p >= r: return 
            mid = (p + r)//2
            sort(nums, p, mid)
            sort(nums, mid + 1, r)
            merge(nums, p, mid, r)
        
        n = len(nums)
        sort(nums, 0, n-1)
        return nums

```


选择排序：
```
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        for i in range(n):
            min = i
            for j in range(i + 1, n):
                if nums[j] < nums[min]: min = j
            nums[i], nums[min] = nums[min], nums[i]
        return nums
```


插入排序：
```
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        for i in range(1, len(nums)):
            value = nums[i]
            for j in range(i - 1, -1, -1):
                if value >= nums[j]:break
                else:nums[j + 1], nums[j] = nums[j], value
        return nums
```


冒泡排序：
```
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        n = len(nums)
        for i in range(n):
            f = 1
            for j in range(0, n - i - 1):
                if nums[j] > nums[j + 1]:
                    nums[j], nums[j+1] = nums[j+1], nums[j]
                    f = 0
            if f: break
        return nums
```
计数排序：
```
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:
        low, high = min(nums), max(nums)
        k = [0 for _ in range(0, high - low + 1)]
        for i in nums:k[i - low] += 1
        for i in range(1, len(k)):
        	k[i] += k[i - 1]
        s = [0 for _ in range(len(nums))]
        for i in nums:
        	k[i - low] -= 1
        	s[k[i - low]] = i
        return s
```



