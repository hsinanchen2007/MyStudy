
一开始考虑了一种 two pointer 的思路：

1. 将 n 个数组打平 => 排序；
2. 记录每个元素是所属的数组下标；
3. 预处理每个所属数组的计数；
4. two pointer 向中间移动，如果计数均大于 0，则取 `l` 和 `r` 记录；

但是会遇到一个问题，就是如果向中间逼近？如果确定缩小方向。其实只要移动到边界就可以处理。

---

既然需要移动到边界，那么为什么我们不维护一组数据，这组数据中每个数组各有一个元素。在扩大数组的时候，我只要将这组数据中的最小值，使用它所处的数组下一位来替换，反复这个操作，直到某一数组结束，就得到了所有的备选答案。

在这种情况下，我们只要维护这组数据的最大值和最小值就可以了。因为修改的是最小值，那么最小值需要我们计算，最大值只要加入的时候对比一下即可。

所以计算最小值，用 `priority_queue` 实现 `logn` 复杂度查询，维护一个下标数组，来对多个数组做偏移。就完成了这道题的求解。

```python
class Solution:
    def smallestRange(self, nums: List[List[int]]) -> List[int]:
        if len(nums) == 1:
            return [min(nums[0]), max(nums[0])]
        
        from queue import PriorityQueue as PQ
        idxs, pq = [0 for _ in nums], PQ()
        
        # 记录最大值优化 
        mm = -100006
        
        # 预处理
        for i, sub in enumerate(nums):
            mm = max(mm, sub[0])
            pq.put((sub[0], i))
            
        le, re = -100006, 100006    
            
        while True:
            #print("pq: ", pq.queue)
            rep = pq.get()    
            l, r, arr_i = rep[0], mm, rep[1]
            r = mm
            if re - le > r - l:
                re, le = r, l
            if idxs[arr_i] + 1 >= len(nums[arr_i]):
                break    
            idxs[arr_i] += 1   
            pq.put((nums[arr_i][idxs[arr_i]], arr_i))
            mm = max(nums[arr_i][idxs[arr_i]], mm)
        return [le, re]     
```