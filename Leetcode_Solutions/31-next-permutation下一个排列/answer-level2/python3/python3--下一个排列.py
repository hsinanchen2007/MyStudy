一开始想的也不是很明白，参考了网友的解法而豁然开朗。可以分为这么几步：
1.边界情况过滤（已经有序；数组长度<=1）
2.从后向前遍历，如果发现nums[i-1] < nums[i]，即存在升序的情况，记录此时位置为 k = i - 1
3.从后向前遍历(nums[-1] --> nums[i])，找到比 nums[k] 大的情况，记录位置为 j，并break
4.交换 nums[k] 和 nums[j]，最后将 nums[k+1] 到 nums[-1] 部分从小到大排序即可。
```
class Solution:
    def nextPermutation(self, nums: List[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        tmp = nums
        if len(nums) <= 1:
            return
        if sorted(nums, reverse=True) == tmp: # 已经是从大到小排序
            nums.sort()
            return 
        elif sorted(nums) == tmp: # 已经是从从小到大排序
            tmp = nums[-2]
            nums[-2] = nums[-1]
            nums[-1] = tmp
            return
        
        for i in range(len(nums)-1, 0, -1): # 倒着排序
            if nums[i] <= nums[i-1]: 
                continue
            k = i - 1
            for j in range(len(nums)-1, i-1, -1):
                if nums[j] > nums[k]:
                    break
            break
        # 交换 nums[k] 和 nums[j]
        tmp = nums[k]
        nums[k] = nums[j]
        nums[j] = tmp
        # nums[k+1] --> nums[-1] 从小到大排序
        
        tmp = nums[k+1:]
        tmp.sort()
        for i in range(k+1, len(nums)):
            nums[i] = tmp[i - k -1]
        
        return
```
