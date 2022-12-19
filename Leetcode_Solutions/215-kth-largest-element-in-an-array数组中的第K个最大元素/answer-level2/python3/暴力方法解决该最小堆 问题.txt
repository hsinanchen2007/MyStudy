### 解题思路
在未排序的数组中找到第 k 个最大的元素。请注意，你需要找的是数组排序后的第 k 个最大的元素，而不是第 k 个不同的元素。
找规律，输入 [3,2,1,5,6,4]：
    若 k = 2,则index = 4,res_value = 5
    若 k = 3,则index = 3,res_value = 4
不难发现，index = len(nums) - k,直接返回排序后的nums[len(nums) - k]即可


### 代码

```python3
class Solution:
    def findKthLargest(self, nums: List[int], k: int) -> int:
        nums.sort()
        return nums[len(nums) - k]



```