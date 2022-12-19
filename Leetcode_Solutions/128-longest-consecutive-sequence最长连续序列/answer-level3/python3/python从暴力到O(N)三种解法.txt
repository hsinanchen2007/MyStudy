```
<!-- 看了下官方题解，思路一样..看来大家思维都一样，从易到难，本题没有dp,dp是一种好思想，但是面试的思路容易卡壳，还是需要多练习的 -->
# 暴力法，大力出奇迹
class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        # ---------------------1 method---------------------
        # 暴力法..emmm 暴力法果然会超时。。
        n = len(nums)
        res = 0
        for num in nums:
            cnt = 1
            while num+1 in nums:
                cnt += 1
                num = num + 1
            res = max(cnt,res)
        return res
# 排序法
# 排序法应该很容易想到，没思路的话先排序哈哈
class Solution1:
    def longestConsecutive(self, nums: List[int]) -> int:
        # ---------------------2 method---------------------
        # 排序O(NlogN)，不满足题意要求O(N),时间60ms,比使用hash的O(N)更快，看起来还行？
        # 使用set去重，然后排序
        nums = list(set(nums))
        nums.sort()
        print(nums)
        n = len(nums)
        # 注意这里res初始化为1 
        res = 1
        cnt = 1
        if n < 2:
            return n
        计数法
        for i in range(n-1):
            if nums[i] + 1 == nums[i+1]:
                cnt += 1
                res = max(cnt,res)
            else:
                cnt = 1
        return res

class Solution3:
    def longestConsecutive(self, nums: List[int]) -> int:
        # ---------------------3 method---------------------
        # 思考，题目要求是O(N)解决，联想到线性时间复杂度解决，应该可以想到使用hash表等辅助结构
        # 使用hash表 时间复杂度O(N),因为hashSet等结构的set,get都是O(1)
        hashSet = set()
        n = len(nums)
        res = 1
        # 构建hashSet
        if n < 2:
            return n
        for i in range(n):
            hashSet.add(nums[i])
        for i in range(n):
            if nums[i] - 1 not in hashSet:
                cnt = 1
                tmp = nums[i]
                while tmp + 1 in hashSet:
                    cnt += 1
                    tmp += 1
                res = max(res, cnt)
        return res 
```
