### 解题思路
有一点类似于习题 [560. 和为K的子数组](https://leetcode-cn.com/problems/subarray-sum-equals-k/)

官方题解巧妙的处理得到倍数和取模的关系。
+ (nums[:i] - nums[:j]) = k*n  <=>  (nums[:i] - nums[:j])%k == 0 <=> nums[:i]%k == nums[:j]%k
官方题解额外记录了下标 j, 来判断是否长为 2。但这里需要注意可能有 j1, j2 满足 nums[:j1] == nums[:j2]
这时候应该保留小的那个下标 min(j1, j2)


k 取值的特例需要额外处理：
+ k = 0, 这时候取模运算会直接报错  2%0. 这时候只有在 nums 中连续出现两个 0 才返回 True
+ k < 0, 由于注意到：所有 nums 都是非负数，n 可以取任何整数，例如可以取 -1, 故我们可以令 k = -k
+ k > 0, 直接处理，但要注意，可能有  nums[:i] 恰好为 k, 故需要在 set 中补 0
+ k > 0 还要注意， 对于 [1,4,6],6 这个是不应该通过的，因为最小长度为 2， 所以还需要加一个判断 nums[i] !=k
+ 但是 [6,6] 6 应该通过, 加一个额外判断 nums[i-1]==k and nums[i]==k


### 代码

```python3
class Solution:
    def checkSubarraySum(self, nums: List[int], k: int) -> bool:
        # 这里大小为 2 需要额外处理
        # 仍然考虑使用 hash 表
        # hash_set = dict()  # val: [i1, i2,]  i1, i2 代表 sum(nums[:i1+1]) = val, sum(nums[:i2+1]) = val
        # hash_set[0] = [-1]
        if k == 0:
            for i in range(1, len(nums)):
                if nums[i] == 0 and nums[i-1] == 0:
                    return True
            return False
        if k<0:
            k = -k
        if len(nums) <= 1:
            return False
        hash_set = set()
        hash_set.add(0)  # 特例： cur == k
        cur = 0
        for i in range(len(nums)):
            cur += nums[i]
            #if k-cur%k in hash_set:  # 写错的 [4,1,5], [4,1,11] 6 不 work，  
            if nums[i]%k != 0 and cur % k in hash_set:  # [1,2,5,6] 6 
            #避免 nums[:i] - nums[:i-1] 仅单个元素
                return True
            elif i>=1 and nums[i]%k == 0 and nums[i-1]%k==0: #[6,6] 6 过不了
                return True
            else:
                hash_set.add(cur%k)
        return False

```