前言：在做这道题前，强烈建议先完成[LeetCode.300 最长上升子序列](https://leetcode-cn.com/problems/longest-increasing-subsequence/)。
此外，此题和[Leetcode.354 俄罗斯套娃信封问题](https://leetcode-cn.com/problems/russian-doll-envelopes/)可以理解为一道题。

解决LIS类问题，最直接的灵感是DP。dp[i]表示在i个元素时，其LIS的长度。算法复杂度为O(n^2)
```
class Solution(object):
    def lengthOfLIS(self, nums):
        if not nums:
            return 0
        dp = [0] * len(nums)
        res = 1
        for i in range(len(nums)):
            tmp = 1
            for j in range(i):
                if nums[i] > nums[j]:
                    tmp = max(tmp, dp[j] + 1)
            dp[i] = tmp
            res = max(res, dp[i])
        return res
```
但是DP解法是有优化空间：
举个例子num = [1, 2, 5, 3, 7]，显然dp[2] = 3 (所对应的LIS为[1, 2, 5])，dp[3] = 3 (所对应的LIS为[1, 2, 3])。当i = 4时，由于num[2] < num[3]，并且dp[3] >= dp[2] (此处有贪心思想)，所以dp[4]的时候不需要考虑dp[2]。

因此，我们使用贪心 + 二分查找来优化我们的算法。
tail[i]表示的是，nums = nums[:i+1]的时候，其最长LIS的末尾元素值，因此tail的实际长度就等于nums的LIS的实际长度。

以nums = [1, 2, 5, 3, 7]为例:
tail[0]：长度为1 -> [1]; [2]; [5]; [3]; [7] -> 1
tail[1]：长度为2 -> [1,2]; [1,5]; [1,3] ,…, [3, 7] -> 2
tail[2]：长度为3 -> [1,2,5], [1,2,3] ,…, [2,5,7] -> 3

我们可以容易得出tail是单调递增的。原因：tail[0] = min(nums)，而我们假设tail[1]的连续上升序列为(nums[i], nums[i+1])，显然nums[i] >= min(nums)，nums[i+1] > nums[i]。所以tail[1]必然大于tail[0]。

当我们遍历nums的时候，
如果nums[i] > tail[size]，tail[size + 1] = nums[i]
如果nums[i] < tail[size]，我们把大于nums[i]最少的tail[j]替换成nums[j] （由于tail是单调递增，所以此处用二分查找）
但是请注意，tail并不等同于nums的LIS，原因在于tail会由于“贪心”，而不停的更新其内部，确认tail的各个元素是最小的。
举个简单例子 nums = [1, 2, 8, 4]
tail[0] = 1
tail[1] = 2
tail[2] = 4

算法复杂度 = iterate the elements * binary search = O(nlogn)
```
class Solution(object):
    def lengthOfLIS(self, nums):
        if not nums: return 0
        tail = [0] * len(nums)
        size = 0 # tail 实际长度
        for num in nums:
            i, j = 0, size
            while i != j:
                mid = (i + j) // 2
                if tail[mid] < num: i = mid + 1
                else: j = mid
            tail[i] = num
            if i == size: size += 1;
        return size
```
回到本题，由于涉及到两个维度 - 身高和体重，我们可以将输入排序，转化为LIS问题求解。
需要注意的是，如果将身高以升序排序，体重需降序排序 `actors.sort(key=lambda x:(x[0], -x[1]))`。
例如height = [1, 2, 3, 2, 2] weight = [0, 4, 3, 1, 3]
height以升序排序而weight升序排序，排序结果为[0, 1, 3, 4, 3]，其LIS为[0, 1, 3, 4] 
height以升序排序而weight降序排序，排序结果为[0, 4, 3, 1, 3]，其LIS为[0, 1, 3]

附上代码：
```
class Solution(object):
    def bestSeqAtIndex(self, height, weight):
        if not height: return 0
        length = len(height)
        actors = [(height[i], weight[i]) for i in range(length)]
        actors.sort(key=lambda x:(x[0], -x[1]))
        tail = [0] * length
        size = 0
        for actor in actors:
            i, j = 0, size
            while (i != j):
                mid = (i + j) // 2
                if tail[mid] < actor[1]: i = mid + 1
                else: j = mid            
            tail[i] = actor[1]
            if i == size: size += 1
        return size
```
有不懂的可以在下面留言 :D