这道题的题解好少，这道题还是挺不错的，解法也很多，我这里用简单的归并排序的思想吧。
归并的话大家也都懂，需要注意的是这道题的特殊之处，归并的逻辑怎么处理？
我大概讲一下这道题的归并思路:
1.建立一个前缀和数组，注意这个前缀和数组有一个初始值0
2.对这个前缀和数组做归并处理
    比如当前数组array是[0,0] low=0 up=0
    前缀和数组是[0,0,0]
    对前缀和做归并
        left:[0]    right:[0,0]
        right:[0,0]这个数组会得到数组array[0,0]中的区间{0,0},cnt+1
        归并处理:
            right中[0,0]中的第一个0与初始值left中的0进行比较，这个时候就会得到array[0,0]中的区间{0},cnt+1
            同理，第二个0会得到区间{0},cnt+1
        总共cnt=3
```
import bisect
class Solution:
    # def countRangeSum(self, nums: List[int], lower: int, upper: int) -> int:
    #     # 前缀和数组初始化
    #     preSum = [0]
    #     # 构造前缀和数组
    #     for i in nums:
    #         preSum += [preSum[-1] + i]
    #     ans = 0
    #     queue = []
    #     # 逆序遍历前缀和数组
    #     for pi in preSum[::-1]:
    #         # 当前前缀和的两个边界
    #         i, j = pi + lower, pi + upper
    #         left = bisect.bisect_left(queue, i)
    #         right = bisect.bisect_right(queue, j)
    #         ans += right - left
    #         bisect.insort(queue, pi)
    #     return ans
    #  归并排序
    def countRangeSum(self, nums: List[int], lower: int, upper: int) -> int:
        # 构造前缀和数组
        n = len(nums)
        preSum = [0 for i in range(n + 1)]
        if nums is None or len(nums) == 0:
            return 0
        for i in range(n):
            preSum[i + 1] = preSum[i] + nums[i]
        # 前缀和数组中必须有一个前缀0作为辅助位置
        return self.merge(preSum, lower, upper)
    '''
    归并的思想，归并思路大家应该都懂，但是需要注意的是为什么将前缀和数组preSum中的第一个辅助位置初始值0的数不去掉？
    这是因为有单个值就满足条件的情况
    比如 [0,0] 0~0
    这个时候有3个满足条件的区间，前缀数组和是[0,0,0]
    这样单个值也会和初始值0进行比较
    '''
    def merge(self, nums: List[int], lower, upper):
        if len(nums) <= 1:
            return 0
        cnt = 0
        n = len(nums)
        mid = n // 2
        left = nums[:mid]
        right = nums[mid:]
        cnt += self.merge(left, lower, upper)
        cnt += self.merge(right, lower, upper)
        i = 0
        j = 0
        low = 0
        up = 0
        # 归并过程
        while i < mid:
            # 高能，我这里原来吧len(right)写成了len(left)，上班时间单点调试了半天。。。一定要小心哦，fuck!
            while low < len(right) and right[low] - left[i] < lower:
                low += 1
            while up < len(right) and right[up] - left[i] <= upper:
                up += 1
            cnt += up - low 
            i += 1
        # 归并排序过程
        i = 0
        j = 0
        k = 0
        while i < len(left) and j < len(right):
            # 谁小移动谁
            if left[i] < right[j]:
                nums[k] = left[i]
                i += 1
            else:
                nums[k] = right[j]
                j += 1
            k += 1
        # 总有一个要出界
        while i < len(left):
            nums[k] = left[i]
            k += 1
            i += 1
        while j < len(right):
            nums[k] = right[j]
            k += 1
            j += 1
        return cnt
```
