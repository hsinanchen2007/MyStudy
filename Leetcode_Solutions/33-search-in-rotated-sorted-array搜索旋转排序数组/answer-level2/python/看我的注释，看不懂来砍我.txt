### 解题思路
直接看注释吧，思路很清晰。
### 代码

```python3
class Solution:
    def search(self, nums: List[int], target: int) -> int:
        mid, left, right = 0, 0, len(nums)-1
        while left <= right:  # 二分法
            mid = (left + right) // 2
            
            if nums[mid] == target:# 找到该点索引值
                return mid
    
            # 旋转点T在mid右区间
            # [left......mid....T....right]
            if nums[left] <= nums[mid]:  
                # target在[left,mid)的升序空间中
                if nums[left] <= target < nums[mid]:
                    right = mid
                # target在(mid,T]或者[T,right]中
                else:
                    left = mid + 1

            # 旋转点T在mid左区间
            # [left...T...mid........right]
            elif nums[left] > nums[mid]:
                # target在(mid,right]的升序空间中
                if nums[mid] < target <= nums[right]:
                    left = mid + 1
                # target在[left,T]或者[T，mid)
                else:
                    right = mid
        # 未找到该点
        return -1

```