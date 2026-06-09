
```python []
class Solution:
    def jump(self, nums: List[int]) -> int:
        #因为当前数字是能跑最远的地方，所以下一个地点是能跑最远的地方
        res = 0
        cur = 0 # 当前位置
        while(nums[cur]+cur<len(nums)-1):
            # 寻找下一个点
            # 进入循环说明当前位置跳不到最后，需要寻找下一个点
            res += 1
            # 下一个点是能跑最远的点
            next_step = cur+1
            max_dist = next_step+nums[next_step]
            for i in range(1,nums[cur]+1):
                cur_max_dist = cur+i+nums[cur+i]
                if cur_max_dist>max_dist:
                    next_step = cur+i
                    max_dist = cur_max_dist
            cur = next_step
        return res+1 if len(nums)>1 else res
```
