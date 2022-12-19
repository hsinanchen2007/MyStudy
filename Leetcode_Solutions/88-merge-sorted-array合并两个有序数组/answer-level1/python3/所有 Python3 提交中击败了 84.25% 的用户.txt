### 解题思路
此处撰写解题思路
思路：
1、定位目标  当mid大于target的时候,right = mid  而不是mid-1 ,因为原表中可能没有target
2、num1插入的同时，释放最后一个节点
### 代码

```python3
class Solution:
    def merge(self, nums1: List[int], m: int, nums2: List[int], n: int) -> None:
        """
        Do not return anything, modify nums1 in-place instead.
        """
        left, right = 0, m
        for i in range(n):
            index = self.findleftest(nums1[left: right], nums2[i])
            nums1.insert(index, nums2[i])
            right += 1
            nums1.pop()
        return

    def findleftest(self, nums: List[int], target: int):
        left, right = 0, len(nums)
        while left < right:
            mid = left + (right - left) // 2
            if nums[mid] == target:
                return  mid
            elif nums[mid] > target:
                right = mid
            else:
                left = mid + 1
        return left

```