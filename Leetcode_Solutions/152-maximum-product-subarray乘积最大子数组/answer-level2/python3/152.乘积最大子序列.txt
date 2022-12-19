唉，我太蠢了，记录一下
动态算法：
维护一个最大值和一个最小值
（负负得正，所以需要维护最小值）
```
class Solution:
    def maxProduct(self, nums: List[int]) -> int:

        #最蠢的暴力搜索
        # listLen, maxdot_list = len(nums), []
        # if listLen == 1:
        #     maxdot = nums[0]
        # else:
        #     for i in range(listLen-1):
        #         new_maxdot = maxdot = nums[i]
        #         i_dot_list = []
        #         for j in range(i+1,listLen):
        #             new_maxdot *= nums[j]
        #             i_dot_list.append(new_maxdot)
        #         maxdot_list.append(max(i_dot_list))
        #     nums.append(max(maxdot_list))
        #     maxdot = max(nums)
        # return maxdot

        # 神仙代码：
        # over_nums, listLen = nums[::-1], len(nums)
        # for i in range(1,listLen):
        #     nums[i] *= nums[i-1] or 1
        #     over_nums[i] *= over_nums[i-1] or 1
        # return max(max(nums),max(over_nums))

        #动态规划dp算法
        # per_max = per_min = res = nums[0]
        # for num in nums[1:]:
        #     cur_max = max(per_max*num,per_min*num,num)
        #     cur_min = min(per_min*num,per_max*num,num)
        #     res = max(res,cur_max)
        #     per_max = cur_max
        #     per_min = cur_min
        # return res

        #上面dp算法中，重复的代码不是好代码,又不重复，又少了参数
        per_max = per_min = res = nums[0]
        for num in nums[1:]:
            compute_list = [per_max*num, per_min*num, num]
            per_max = max(compute_list)
            per_min = min(compute_list)
            res = max(res,per_max)  
        return res
        



```
