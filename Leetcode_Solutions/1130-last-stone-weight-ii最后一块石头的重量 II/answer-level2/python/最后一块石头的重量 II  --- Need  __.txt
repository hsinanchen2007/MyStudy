### 解题思路
1. 此题是 [1046. 最后一块石头的重量](https://leetcode-cn.com/problems/last-stone-weight/) 的扩展
    - 唯一区别是：每一回合，从中选出**两块最重的石头**，然后将它们一起粉碎。假设石头的重量分别为 x 和 y，且 x <= y；最后，最多只会剩下一块石头。返回此石头的重量。如果没有石头剩下，就返回 0。
    - 更改为 **任意的两块石头**，最后，最多只会剩下一块石头。**返回此石头最小的可能重量**。如果没有石头剩下，就返回 0

2. 貌似采用 两块最重的石头 也可以解决此题目
    - **case : 31 26 33  21  40 **,通过不了的
    - **得采用 0-1 背包解决问题**



### 代码

```python3
class Solution:
    def lastStoneWeightII(self, stones: List[int]) -> int:
        n = len(stones)
        nums = stones 
        if n == 1:
            return nums[0]
        
        

        sum_ = sum(nums)
        half = sum_ // 2

        dp = [0 for i in range(half+1)]

        for i in range(n):
            for j in range(half, nums[i]-1, -1):
                dp[j] = max(dp[j-nums[i]] + nums[i], dp[j])
        
        return sum_ - dp[half] *2
```