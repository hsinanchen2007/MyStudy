
# 方法一：二分法
```
class Solution:
    def searchRange(self, nums: list, target: int) -> list:
        start = 0
        end = len(nums)-1
        while start <= end:
            middle = (start+end)//2
            print(f'start: {start}; end: {end}; middle: {middle}; value: {nums[middle]}')
            if nums[middle] > target:
                end = middle-1  # 很重要的点，end=middle-1而不是end=middle，这样可以比较简单地处理当流程走到最左边的时候，start=middle+1同理
            elif nums[middle] < target:
                start = middle+1
            else:
                i = middle
                while i>start:
                    print(f'i: {i}; start: {start}')
                    if nums[i-1] == target:
                        i -= 1
                    else:
                        break
                j = middle
                while j < end:
                    print(f'j: {j}; end: {end}')
                    if nums[j+1] == target:
                        j += 1
                    else:
                        break
                return [i, j]
        return [-1, -1]
```

# 方法二：index+count
```
class Solution:
    def searchRange(self, nums: list, target: int) -> list:
        if target not in nums:
            return [-1, -1]
        start = nums.index(target)
        count = nums.count(target)
        return [start, start+count-1]
```