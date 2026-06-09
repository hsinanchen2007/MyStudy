### 解题思路 
此处撰写解题思路

### [代码](https://leetcode-cn.com/problems/maximum-gap/solution/tong-pai-xu-by-powcai/)

```python
class Solution:
    def maximumGap(self, nums: List[int]) -> int:
        n = len(nums)
        if n < 2: return 0
        max_num = max(nums)
        min_num = min(nums)
        gap = math.ceil((max_num - min_num)/(n - 1))
        bucket = [[float("inf"), float("-inf")] for _ in range(n - 1)]
        #print(bucket)
        # 求出每个桶的最大值，和最小值
        for num in nums:
            if num == max_num or num == min_num:
                continue
            loc = (num - min_num) // gap
            bucket[loc][0] = min(num, bucket[loc][0])
            bucket[loc][1] = max(num, bucket[loc][1])
        ##print(bucket)
        # 遍历整个桶
        preMin = min_num
        res = float("-inf")
        for x, y in bucket:
            print(x,y)
            if x == float("inf") :
                continue
            res = max(res, x - preMin)
            preMin = y
        res = max(res, max_num - preMin)
        return res
```