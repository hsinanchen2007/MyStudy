### 解题思路


### 代码

```python3
from math import ceil
class Solution(object):
    def maximumGap(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        桶排序
        为什么是max-min？
        我觉得是因为桶的size是根据区间长度以及数组的长度去推算的，在假设数组的分布是最均匀的情况以及规定桶的size是左开右闭区间，所以在一开始算数组的区间长度的时候这个区间也是取左开右闭的，然后最后的一个数是单独给她分配一个桶。因为是左开右闭，所以才是用max-min
        从大家举例的 2 4 6 8 这个例子来看
        桶长度 6/3=2，(如果桶的长度不是整数的话可以向上取整，因为在取整数的情况下[0,1.5) 和[0,2)是一样的)
        桶数量 6/2+1（为8分配一个桶）
        """
        if len(nums)<=1:
            return 0
        min_value = min(nums)
        max_value = max(nums)
        if max_value==min_value:
            return 0

        N = len(nums)
        bucket_size = ceil((max_value-min_value)/(N-1))
        bucket_num = max(1, (max_value-min_value)//bucket_size)+1
        
        bucket_min_max = [[False, float('inf'), float('-inf')] for _ in range(bucket_num)]
        for i in range(len(nums)):
            bucker_i = (nums[i]-min_value)//bucket_size
            bucket_min_max[bucker_i][0]=True
            min_i, max_i = bucket_min_max[bucker_i][1:]
            bucket_min_max[bucker_i][1] = min(min_i, nums[i])
            bucket_min_max[bucker_i][2] = max(max_i, nums[i])


        res = 0
        
        prev_max = bucket_min_max[0][2]
        # 第一个箱子有最小值
        for i in range(1, bucket_num):
            if not bucket_min_max[i][0]:
                continue
            res = max(res, bucket_min_max[i][1]-prev_max)
            prev_max = bucket_min_max[i][2]
        
        return res


            




        

```