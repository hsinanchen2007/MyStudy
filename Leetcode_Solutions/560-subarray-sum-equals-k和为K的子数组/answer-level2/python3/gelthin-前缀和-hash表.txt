### 解题思路
先前在网上的一个博客看到此题，感觉很有可能要考到。
zhuyn 的tx 面试题。


有点类似习题 [303. 区域和检索 - 数组不可变](https://leetcode-cn.com/problems/range-sum-query-immutable/)

#### 1.前缀和的思路， 复杂度 O(n^2)
``` python3
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        #前缀和 303. 区域和检索 - 数组不可变
        if len(nums) <= 0:
            return 0
        tmp = 0
        cum_sum = []
        cum_sum.append(0) # 增加一个虚拟0， 边界条件好处理
        for x in nums:
            tmp += x
            cum_sum.append(tmp)
        # O(n^2)   [i, j]
        res = 0
        for i in range(len(nums)):
            for j in range(i+1, len(nums)+1):  # 至少1个数
                if cum_sum[j] - cum_sum[i] == k:
                    res += 1
        return res
```
这里如果调整遍历次序，例如 start = 0, end = 1,2,3,4,... 再来 start=1, end=2,3... 可以省去额外的空间。


#### 2.考虑利用用一个 hash 表来进行记录，改进前面前缀和的思路。
可以这样做，当我们计算完了 nums[0:i+1] 的和的时候，观察是否存在某个或者某些 j<i 满足，
+ sum(nums[0:i+1]) - sum(nums[0:j+1]) = k 。若有，我们就找到了一组 [i,j] 满足条件。
如果我们在计算过程中把 sum(nums[0:j+1]) 的值都存储到 set 中，我就只需要检查 set 中有没有这样的值恰好等于 sum(nums[0:i+1])-k。 进一步，为了统计个数，我不用 set, 而用 hash 表（计数数组），统计sum(nums[0:j+1]) 的值出现的次数。
然后再利用这个计数数组去查看有多少个不同的 j 满足 sum(nums[0:j+1]) = sum(nums[0:i+1])-k  (j<i)，累加这个值即可。

这一个 hash 表的 idea 在 二数之和，[三数之和](https://leetcode-cn.com/problems/3sum/solution/three-sum-ti-jie-by-wonderful611/)也有应用。



### 代码
```python3
class Solution:
    def subarraySum(self, nums: List[int], k: int) -> int:
        #前缀和 303. 区域和检索 - 数组不可变

        if len(nums) == 0:
            return 0
        hash_set = dict()
        hash_set[0] = 1  # 前缀和为 0 出现了1次, 以保证不会漏过 nums[0:i+1] 恰好为 k 的情形
        res = 0
        cur = 0
        for i in range(len(nums)):
            cur += nums[i] # cur 代表 nums[0:i+1] 的和，考虑是否有 j<i, 满足 nums[0:j+1] = nums[0:i+1]- k
            if cur-k in hash_set:  # 当 cur-k==0, 这里需要特殊处理
                res += hash_set[cur-k] # 当计算到 nums[0:i+1] 时， nums[0:j+1] (j<i) 已经全部计算出来了
            if cur in hash_set:
                hash_set[cur] += 1
            else:
                hash_set[cur] = 1
        return res
```