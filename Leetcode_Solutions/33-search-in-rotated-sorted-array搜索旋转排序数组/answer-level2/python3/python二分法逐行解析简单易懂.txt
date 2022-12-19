### 解题思路
题目要求时间复杂度O(logn)，即已经提示用二分法
给出的数组在某个点上进行了旋转，即说明在这个点的左边(包括这个点)是升序，该点最大
在这个点的右边(不包括这个点)也是升序，但是小于数组的第一个。

首先找数组中点下标，并判断旋转点在中点左边还是右边
①当nums[left]<=nums[mid]时，左边升序排列，旋转点在右边
    此时，若nums[left] <= target <= nums[mid]，说明target在左边，改right = mid
    否则，改left = mid+1
②当nums[left]>nums[mid]时，右边升序排列，旋转点在左边
    此时，若nums[mid] < target < nums[left]，说明target在右边，改left = mid+1
    这里不等式不加等号是因为 mid和left 两个数都放在左区间了，右区间中不可能有左区间的数
    否则，改right = mid

最后left == right时，循环结束，返回left的值，即为target下标
### 代码

```python3
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        left = 0
        right = len(nums) - 1
        mid = 0
        while left < right:
            mid = (left+right) // 2
            #旋转点在右区间
            if nums[left] <= nums[mid]:
                #target在左区间
                if nums[left] <= target <= nums[mid]:
                    right = mid
                #target在右区间
                else:
                    left = mid +1

            #旋转点在左区间
            else:
                #target在右区间
                if nums[mid] < target < nums[left]:
                    left = mid +1
                #target在左区间
                else:
                    right = mid 
        
        if left == right and target == nums[left]:
            return left
        else:
            return -1
```