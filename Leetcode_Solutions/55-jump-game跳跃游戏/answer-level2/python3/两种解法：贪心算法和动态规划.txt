### 解题思路
第一种解法：贪心算法。
这个算法其实只能寻求局部最优，整体是否是最优有待证明hh。
假设input是一个长度为n的数组。
如果我们从前往后遍历，那么，对于第一个位置，如果它直接可以跳到最后的位置，那么问题就结束了。
否则，我们将进行一次跳跃，但是跳跃的步子迈多大呢？这是个问题。起码我们不应该直接迈当前的最大步数，不然可能就被卡死了。
参见例子： [2,3,0,1]。在第一位如果直接跳两步，那么就到了第三位0的位置，反而不能继续前进了。然而，如果我们直跳一步，在3的位置就可以到达最后一位。
那么我们尝试这样的策略：在最大的步子允许的范围内，迈一个步子，使得迈下这个步子之后的位置的“脚力所及”（可以迈的最大步数加上它的index）最大。
当然这个策略不一定是对的，但是对于测试样例、提交都可以通过。again，这个算法的正确性有待证明。


第二种解法：动态规划。
假设input是一个长度为n的数组。
如果我们能够从0跳到 n-1,那么我们必然可以从0跳到 n-k1, 对于某个 k1值成立。
如果我们能够从0跳到 n-k1,那么我们必然可以从0跳到 n-k2, 对于某个k2值成立。
......以此类推, 直到我们发现其实存在某个 k,使得我们根本无法从 0跳到 n-k的位置。那就说明我们根本到不了终点。
于是就有如下思路：从后往前面遍历，先把target_index初始化为最后一位。
我们如果遇到了某个位置 loc，使得我们可以跳到 target_index,那么问题就转化为了是否存在路径使得我们可以从0跳到 loc。
与此同时，我们将 loc设定为新的 target_index。
子问题就这样循环嵌套，直到我们的 loc到达0为止。
这时，如果我们真的可以从0跳到最后一位，那么我们必然可以从 0跳到此时的 target_index，如果真的是这样，那么让 target_index = loc = 0；反之 target_index != 0
最后做判断只需要看 target_index是否等于0就可以了！


### 代码

# 解法一：贪心算法
```python3
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums)
        if n <= 1: # corner case
            return True
        # 从前往后
        loc = 0
        bound = 1
        while loc < n-1:
            if loc + nums[loc] >= n-1:
                return True
            temp = nums[bound: loc+nums[loc] + 1]
            if temp == []:
                return False
            # initialize
            max_jump_index = 0
            max_jump = max_jump_index + temp[max_jump_index]
            for i in range(len(temp)):
                if temp[i] + i + bound > max_jump:
                    max_jump_index = bound + i
                    max_jump = max_jump_index + temp[i]
            bound = loc + nums[loc] + 1
            loc = max_jump_index
        return False
```
# 解法二：动态规划
```python3
class Solution:
    def canJump(self, nums: List[int]) -> bool:
        n = len(nums) 
        # 从后往前
        target_index = n-1
        loc = n-2
        while loc >= 0:
            if loc + nums[loc] >= target_index:
                target_index = loc
            loc -= 1
        return 0 == target_index
            
```