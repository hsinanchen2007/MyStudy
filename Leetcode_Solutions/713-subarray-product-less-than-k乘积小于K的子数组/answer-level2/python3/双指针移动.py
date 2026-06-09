### 解题思路
这道题降低复杂度的关键是重复利用已经计算过的结果。而这题的 input数组中每个元素都是正整数，这是非常关键的。
这意味着 从第i位到第j位的乘积一定会小于等于从第i位到第j+1位的乘积！
于是有如下算法：先初始化第一个指针 p1，cum_prod = 1, result = 0
从 0开始移动 p2, 并将 cum_prod 随之增大。如果 cum_prod 比k小，那么我们就让 result 增加 p2-p1+1；反之，我们就移动 p1, 并随之减小 cum_prod，直到 cum_prod 比 k 小（或者 p1抵达 p2的时候）结束。
为什么这样做呢？事实上，在移动的过程中，只要 cum_prod是小于k的，这就说明数组 nums[p1:p2+1]是一个满足要求的子数组。
特别的，这个子数组是：倘若固定 p2, 那么p1是可以使得 nums[start:p2+1]符合条件的start 的最小值！
因此，我们每找到一个这样的，固定p2后最大的子数组，我们就在 result 增加 p2-p1+1（在 nums[p1:p2+1]中，包含 nums[p2]的所有连续子数组的个数）
由于我们对于每一个 p2都这样做了，所以这样的结果是不会漏解的。


### 代码

```python3
class Solution:
    def numSubarrayProductLessThanK(self, nums: List[int], k: int) -> int:
        n = len(nums)
        result = 0
        p1 = 0
        cum_prod = 1
        for p2 in range(n):
            cum_prod *= nums[p2]
            if cum_prod < k:
                result += p2 - p1 + 1
            else:
                while cum_prod >= k and p1 <= p2:
                    cum_prod /= nums[p1]
                    p1 += 1
                result += p2 - p1 + 1
        return result 

```