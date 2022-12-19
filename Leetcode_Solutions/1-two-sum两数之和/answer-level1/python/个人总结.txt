### 解题思路
打算通过排序后，进行二分查找减少运行时间；期间遇到原顺序（索引）改变——通过复制list解决，获取值的重复问题（开始以为的是list中的所有元素都不存在重复，审题问题，通过remove去除第一个，此时得到的第二索引要+1）


### 代码

```python
class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        copy = nums[:]
        nums.sort()
        total_count = len(nums)

        final_num1 = None
        final_num2 = None

        for i in range(total_count):
            target_j = target - nums[i]
            print(target_j)
            
            if target_j < nums[i] or target_j > nums[total_count - 1]:
                if target_j < nums[i]:
                    break
                continue

            target_index = self.binarySearch(nums, 0, total_count - 1, target_j)

            if target_index == i:
                continue

            if target_index != -1:
                final_num1 = nums[i]
                final_num2 = target_j

        print(final_num1,final_num2)
        i = copy.index(final_num1)

        # 删除,前后问题，重复问题
        if final_num1 == final_num2:
            copy.remove(final_num1)
            j = copy.index(final_num2) + 1
        else:
            j = copy.index(final_num2)
        
        
        print(i,j)
        if i < j:
            return [i,j]
        else:
            return [j,i]
    
    # 返回 x 在 arr 中的索引，如果不存在返回 -1
    def binarySearch (self,arr, l, r, x): 
    
        # 基本判断
        if r >= l: 
    
            mid = int(l + (r - l)/2)
    
            # 元素整好的中间位置
            if arr[mid] == x: 
                return mid 
            
            # 元素小于中间位置的元素，只需要再比较左边的元素
            elif arr[mid] > x: 
                return self.binarySearch(arr, l, mid-1, x) 
    
            # 元素大于中间位置的元素，只需要再比较右边的元素
            else: 
                return self.binarySearch(arr, mid+1, r, x) 
    
        else: 
            # 不存在
            return -1
```