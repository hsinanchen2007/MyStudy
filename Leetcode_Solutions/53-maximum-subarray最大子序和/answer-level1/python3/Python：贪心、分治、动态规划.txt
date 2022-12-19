### 解题思路
我首先写的是两个for循环的滑窗法，结果有一个超多的输入数组，输入规模太大，超出运行时间限制了。之后开始思考利用分治思想来解题，但是发现分界节点囊括不进去，也没想出来解决方法。接着思考利用动态规划去解题，但是新问题又出现了，竟然写不出转移方程!思考了一会没啥结果，在这期间又出现一个新问题，示例答案不是从数组第一个开始的，我该怎么实现不从数组第一个开始，还是最大连续子序列和呢？继续思考，仍然没想出来。好吧，我去看题解了。

下面是我对题解的思考，和对我发现问题的解答。

最后，除了分治思想解题外，我觉得贪心算法和动态规划算法的核心都是发现了这么一个规律：正在访问的节点值+此节点之前的最大值如果大于当前节点，则更新最大值为和，否则更新最大值为当前节点。

### 代码

```python3
class Solution:
    def maxSubArray(self, nums: List[int]) -> int:
        '''
        法三：
        # 
        贪心算法：每一步都选择最佳选择。贪心算法可以在线性时间复杂度内找到数组中的最大值或最小值，以及和的最值问题。

        '''
        lenth = len(nums)
        cur_sum=max_sum = nums[0]
        for i in range(1,lenth):
            cur_sum = max(cur_sum+nums[i], nums[i])
            max_sum = max(cur_sum, max_sum)
        
        return max_sum



        '''
        法二：
        # 180 ms	14 MB, O(n) = NlogN
        分治思想解题。分治思想是将问题分解成一个个小问题，将小问题解决后组成原问题的解，子问题之间没有联系，有自己的解。
        对于此题来说，原问题是求一个数组中连续数字的最大和，将其分为三个子问题，以中间节点问分界线，包括分界点的左部分最大值，不包括分界点的右部分最大值，包括分界点的左右部分最大值，以上三者的最值问题。这是官方给出的分治思路，我试图去理解这么分的原因：
        首先分治思想将原问题分成左右两部分是常规思路，这里的变形是添加了第三部分。如果安装原始的分治思想将数组分为两部分，那么以分界点向左右两个方向辐射的子数组则没有被考虑，不符合题意。因此我认为这是满足题意，修补分治算法在此题上的不足。
        helper函数实现的是分治，求左、中、右的最大值；midSum函数实现的是求第三部分的和。
        其中midSum的结果可以由三部分中组成 0~a + b + c~lenth，其中b是每次遍历到的节点，以mid标记，0~a以left_sum标记，c~lenth以right_sum标记。存在left_sum或right_sum为0的情况。
        '''

        return self.helper(nums, 0, len(nums)-1)
    
    def helper(self, nums, left, right):
        if left == right:
            return nums[left]
        
        mid = (left + right) // 2
        left_sum = self.helper(nums, left, mid)
        right_sum = self.helper(nums, mid+1, right)
        mid_sum = self.midSum(nums, left, right, mid)

        return max(left_sum, mid_sum, right_sum)
    
    def midSum(self, nums, left, right, mid):
        if left == right:
            return nums[left]

        left_subsum = float("-inf")
        cur_sum = 0
        for i in range(mid, left-1, -1):
            cur_sum += nums[i]  # 求 i-n, i-(n-1),```,(i-1), i 中包括i的连续子序列和
            left_subsum = max(cur_sum, left_subsum)
        
        right_subsum = float("-inf")
        cur_sum = 0
        for i in range(mid+1, right+1):
            cur_sum += nums[i]
            right_subsum = max(cur_sum, right_subsum)
        
        return left_subsum + right_subsum



        '''
        法一：
        # 48 ms	14.3 MB O(N) = N
        动态规划解题，优化了存储数组，将存储于dp中的状态存到当前遍历的数组下表中。动态规划的思想是：遍历访问数组中每一个元素，每一次访问到一个元素时，此时的最大值为之前子序列的和加上当前值与当前值的最大值为新的当前最大值。
        当前子序列是从小到大慢慢增加的，每次增大的结果都是局部最优解，考量这么一个事：之前子序列的和为正整数，那么加上当前访问的值大于当前访问的值，说明之前的和当前状态是有增益的，需要保留，若小于当前值，那么说明当前值就是目标的最大值，从当前值继续开始访问后面的。
        我在思考的过程中出现了这个疑问，算法是怎么确定从数组中任意一个位置开始的子序列是最大的？因为算法从第一个元素遍历到最后一个元素，实质上考量了每个值，每个值的状态都是由之前状态和当前值共同确定的，也就是第二段的解释内容。换种思路，既然答案是从数组中某个字符开始的，那么也就说其他任何情况（包括该数或者不包括该数的任和连续组合都不是最大和，也就是说，假设这个数下标为i，那么0~i-1, i+1~lenth, i-j~-i+j都不如当前选择i~i+u和大）。
        状态方程为： dp[i] = max(nums[i], nums[i] + dp[i-1])

        for i in range(1, len(nums)):
            nums[i] = nums[i] + max(nums[i-1], 0)
        
        return max(nums)
        '''        

```