### 解题思路
试着写了个快排

### 代码

```python3
class Solution:
    def sortArray(self, nums: List[int]) -> List[int]:

        def partition(low, high):
            randidx = random.randint(low, high)
            nums[low], nums[randidx] = nums[randidx], nums[low]
            x = nums[low]
            l = low + 1
            r = high 
            while l <= r:
                while l <= r and nums[l] <= x:
                    # l 指向数字肯定比 x 大
                    l += 1
                while l <= r and nums[r] >= x:
                    # r 指向数字肯定比 x 小
                    r -= 1
                if l > r:
                    break
                nums[l], nums[r] = nums[r], nums[l]
            # r 和 low 互换, r为 pivot
            nums[r], nums[low] = nums[low], nums[r]
            return r

        def quicksort(low, high):
            if low < high:
                pivot = partition(low, high)
                quicksort(low, pivot - 1)
                quicksort(pivot + 1, high)
        
        quicksort(0, len(nums) - 1)
        return nums
```