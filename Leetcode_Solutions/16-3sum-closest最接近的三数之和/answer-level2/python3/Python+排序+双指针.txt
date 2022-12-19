### 解题思路
若暴力枚举时间复杂度为 O(n^3)，时间溢出，需要降低复杂度

利用排序后三个数值和的大小关系减少一次遍历：
    先对数组排序
    遍历每一个值nums[i]
        使用前指针指向 start = i + 1 处，后指针指向结尾处 end = nums.length - 1 处
        while start小于end：
            根据 sum = nums[i] + nums[start] + nums[end] 的结果，判断 sum 与 target 的大小关系，因为数组有序，如果 sum > target 则 end--，如果 sum < target 则 start++，如              果 sum == target 则说明距离为 0 直接返回结果
            判断 sum 与目标 target 的距离，如果更近则更新结果res
            
总时间复杂度：O(nlogn) + O(n^2) = O(n^2)


### 代码

```python3
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        res = 0
        dis = float('inf')
        sorted_nums = sorted(nums)
        len_nums = len(sorted_nums)
        for i in range(len_nums):
            first_val = sorted_nums[i]
            start_index = i+1
            end_index = len_nums-1
            while start_index<end_index:
                tri_sum = first_val + sorted_nums[start_index] + sorted_nums[end_index]
                if tri_sum > target:
                    end_index = end_index - 1
                elif tri_sum < target:
                    start_index = start_index +1
                else:
                    return tri_sum
                cur_dis = abs(tri_sum-target)
                if cur_dis<dis:
                    dis = cur_dis
                    res = tri_sum                
        return res
```