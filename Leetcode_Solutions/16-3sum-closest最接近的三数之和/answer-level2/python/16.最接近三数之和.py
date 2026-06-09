### 解题思路
- 初始化最接近target的结果res = float('inf')
- 数组排序，从头开始遍历，设置start = i+1,end = len(nums)-1
路
- 初始化最接近target的结果res = float('inf')
- 数组排序，从头开始遍历，设置start = i+1,end = len(nums)-1
- 计算cur_sum = nums[i]+nums[start]+nums[end]
- 如果cur_sum == target,直接返回cur_sum
- 如果cur_sum < target,nums[start]需要大一些，start = start +1
- 如果cur_sum > target,nums[start]需要小一些，end = end  - 1
- 别忘了更新,res = cur_sum if abs(cur_sum - target) < abs(res-target)

### 代码

```python3
class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        L = len(nums)
        nums.sort()
        res = float('inf')
        history = [] #去重
        for i in range(L-2):
            if nums[i] in history:
                continue
            else:history.append(nums[i])
            start = i+1
            end = L-1
            while start!=end:
                cur_sum = nums[i] +  nums[start] +nums[end]
                if cur_sum == target:return cur_sum
                elif cur_sum < target:start = start + 1
                elif cur_sum > target:end = end -1
                if abs(cur_sum - target) < abs(res - target):
                    res = cur_sum
        return res

```