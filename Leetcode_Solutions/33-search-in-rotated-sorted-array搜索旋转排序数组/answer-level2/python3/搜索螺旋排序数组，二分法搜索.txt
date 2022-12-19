### 解题思路
从中间分开，一边一定有序，这个思路，去判断target在中间的哪一边
### 代码

```python3
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        L = 0
        R = len(nums)-1
        while L <= R:
            mid = L+ (R-L)//2
            if nums[mid] == target:
                return mid
            elif nums[L] <= nums[mid]:
                # 注意这里的=号,当L= mid 时，左边就只有一个元素
                # 左边为升序
                if target >= nums[L] and target < nums[mid]:
                    #target 在左边有序的数组中
                    R = mid-1
                else:
                    # target 在右边无序序列中
                    L = mid+1
            else:
                #右边为升序
                if target <= nums[R] and target > nums[mid]:
                    # target 在右边有序的数组中
                    L = mid+1
                else:
                    #target在左边无序数组中
                    R = mid -1
        return -1 



        

```