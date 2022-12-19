O(n)神仙解法，桶，参考自https://leetcode.com/problems/contains-duplicate-iii/discuss/339421/Python-bucket-method-in-detail

首先，定义桶的大小是**t+1**, **nums[i]//(t+1)**决定放入几号桶,这样在**一个桶里面的任意两个的绝对值差值都<=t**
`例如t=3, nums=[0 ,5, 1, 9, 3,4],那么0号桶就有[0,1,3],1号桶就有[4,5],2号桶就有[9]`

先不考虑索引差值最大为K的限制，那么遍历nums每一个元素，并把他们放入相应的桶中，有两种情况会返回True
- 要放入的桶中已经有其他元素了，这时将nums[i]放进去满足差值<=t
- 可能存在前面一个桶的元素并且与nums[i]的差值<=t 或者 存在后面一个桶的元素并且与nums[i]的差值<=t

根据返回True的第一个条件，可以知道前后桶的元素最多也只能有一个。

接着考虑限制桶中的索引差最大为K,当i>=k的时候：
我们就要去**删除存放着nums[i-k]的那个桶**(编号为`nums[i-k]//(t+1)`)
这样就能保证遍历到第`i+1`个元素时，全部桶中元素的索引最小值是`i-k+1`，就满足题目对索引的限制了



```python
class Solution:
    def containsNearbyAlmostDuplicate(self, nums: List[int], k: int, t: int) -> bool:
        if t < 0 or k < 0:
            return False
        all_buckets = {}
        bucket_size = t + 1                     # 桶的大小设成t+1更加方便
        for i in range(len(nums)):
            bucket_num = nums[i] // bucket_size # 放入哪个桶
            
            if bucket_num in all_buckets:       # 桶中已经有元素了
                return True
            
            all_buckets[bucket_num] = nums[i]   # 把nums[i]放入桶中
            
            if (bucket_num - 1) in all_buckets and abs(all_buckets[bucket_num - 1] - nums[i]) <= t: # 检查前一个桶
                return True
            
            if (bucket_num + 1) in all_buckets and abs(all_buckets[bucket_num + 1] - nums[i]) <= t: # 检查后一个桶
                return True
            
            # 如果不构成返回条件，那么当i >= k 的时候就要删除旧桶了，以维持桶中的元素索引跟下一个i+1索引只差不超过k
            if i >= k:
                all_buckets.pop(nums[i-k]//bucket_size)
                
        return False
            
```
