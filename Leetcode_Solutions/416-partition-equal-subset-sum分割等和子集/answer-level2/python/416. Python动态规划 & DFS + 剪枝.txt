### 解题思路
下面给出了动态规划以及DFS + 剪枝的代码，但是DFS + 剪枝会超时，所以仅仅是提供一个思路，动态规划给出了三种实现，使用的空间越来越小，分别对应使用N \* (sum // 2 + 1)、2 \* (sum // 2 + 1)以及sum // 2 + 1的数组。

### 代码

```python
class Solution(object):
    def canPartition_dfs(self, nums):
        """
        递归 + 剪枝。
        :type nums: List[int]
        :rtype: bool
        """
        length = len(nums)
        if length == 0:
            return True
        sum = 0
        for num in nums:
            sum += num
        if sum % 2:
            return False
        nums.sort(reverse=True) # DFS解决类01背包的问题的时候，让比较大的数更接近根节点，再配合剪枝会大幅提高效率，这样会使搜索树更浅，所以进行倒序排序
        def get_res(temp, ind):
            """
            :param temp -> int: 当前已经积累的总和
            :param ind -> int: 当前已经使用的nums[0:ind]中的数字的和
            """
            if temp > sum // 2 or ind >= length:
                return False
            if temp == sum // 2:
                return True
            use = get_res(temp + nums[ind], ind + 1)
            not_use = get_res(temp, ind + 1) if not use else False
            return use or not_use
        return get_res(0, 0)

    def canPartition(self, nums):
        """
        DP。时间复杂度为O(SN)，空间复杂度为O(N)，S为sum // 2，N为数组元素个数。
        :type nums: List[int]
        :rtype: bool
        """
        length = len(nums)
        if length == 0:
            return True
        sum = 0
        for num in nums:
            sum += num
        if sum % 2:
            return False 
        # 通过迭代公式可以发现迭代公式只和dp[i][j]左上角的元素有关，所以我们可以倒序遍历数组，
        # 这样就可以使得需要的信息被保留，并且充分利用空间，即只用一维数组
        dp = [False] * (sum // 2 + 1) 
        dp[0] = True
        if nums[0] <= sum // 2:
            dp[nums[0]] = True
        for i in range(1, length):
            for j in range(sum // 2, 0, -1):
                use_res = dp[j - nums[i]] if j - nums[i] >= 0 else False
                not_use_res = dp[j]
                dp[j] = use_res or not_use_res
        return dp[-1]

    def canPartition_2(self, nums):
        """
        DP。时间复杂度为O(SN)，空间复杂度为O(N)，S为sum // 2，N为数组元素个数。
        :type nums: List[int]
        :rtype: bool
        """
        length = len(nums)
        if length == 0:
            return True
        sum = 0
        for num in nums:
            sum += num
        if sum % 2:
            return False 
        # 由于在填表的过程中只利用i - 1行的信息，所以我们可以只保存两行
        dp = [[False] * (sum // 2 + 1) for _ in range(2)] 
        for i in range(2):
            dp[i][0] = True
        if nums[0] <= sum // 2:
            dp[0][nums[0]] = True
        for i in range(1, length):
            for j in range(1, sum // 2 + 1):
                use_res = dp[(i - 1) % 2][j - nums[i]] if j - nums[i] >= 0 else False
                not_use_res = dp[(i - 1) % 2][j]
                dp[i % 2][j] = use_res or not_use_res
        return dp[length % 2][-1]

    def canPartition_3(self, nums):
        """
        DP。时间复杂度和空间复杂度都为O(SN)，S为sum // 2，N为数组元素个数。
        :type nums: List[int]
        :rtype: bool
        """
        length = len(nums)
        if length == 0:
            return True
        sum = 0
        for num in nums:
            sum += num
        if sum % 2:
            return False 
        # dp[i][j]的意义是用前i个数字是否能够使得加和为j
        dp = [[False] * (sum // 2 + 1) for _ in range(length)] 
        for i in range(length):
            dp[i][0] = True
        if nums[0] <= sum // 2:
            dp[0][nums[0]] = True
        for i in range(1, length):
            for j in range(1, sum // 2 + 1):
                use_res = dp[i - 1][j - nums[i]] if j - nums[i] >= 0 else False
                not_use_res = dp[i - 1][j]
                dp[i][j] = use_res or not_use_res
        return dp[-1][-1]
```