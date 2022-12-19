写出来的 带 bug 的代码



``` python3
class Solution:
    def maxProduct(self, nums: List[int]) -> int:
        n = len(nums)
        if n == 0:
            return None
        DP_max = []
        DP_min = []
        if nums[0] == 0:
            DP_max.append(1)
            DP_min.append(1)
        elif nums[0] > 0:
            DP_max.append(nums[0])
            DP_min.append(1)
        else:
            DP_max.append(1)  # 这里初始设为 1 很关键，否则样例 [-2,3,4,5,6,0,-1] 过不了
            DP_min.append(nums[0])

        res = nums[0]
        i = 1
        while i<n:
            if nums[i] == 0:
                res = max(res, 0)
                DP_max.append(1) # 加入 1
                DP_min.append(1)
            elif nums[i] > 0:
                DP_max.append(DP_max[i-1]*nums[i])
                DP_min.append(DP_min[i-1]*nums[i])
                res = max(res, DP_max[i-1]*nums[i])
            else: #nums[i]<0
                DP_min.append(DP_max[i-1]*nums[i])
                DP_max.append(DP_min[i-1]*nums[i])  # [3,-1,4]也过不了
                res = max(res, DP_min[i-1]*nums[i])
            i += 1
        return res
```
一直报错
