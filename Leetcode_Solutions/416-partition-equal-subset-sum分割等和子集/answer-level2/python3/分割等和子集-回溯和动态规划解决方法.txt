1. 回溯思想: 先排序数组来减少回溯的节点, 然后通过递归, 遍历所有的可能
2. 动态规划: 使用一维数组memo存储状态    
        1. memo的索引表示数组元素子集相加可以得到的和     
        2. memo的值为真: 存在和为memo索引的子集
```
class Solution:
    '''
    给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
        每个数组中的元素不会超过 100
        数组的大小不会超过 200
    '''
    def canPartition(self, nums) -> bool:
        '''
        回溯思想: 先排序数组来减少回溯的节点, 然后通过递归, 遍历所有的可能
        '''
        s = sum(nums)
        # 假设可以拆分为两个和相等的子集, 数组的和是子集和的两倍, 一定是偶数
        if s % 2 == 1:
            return False
        n = len(nums)
        nums_sort = sorted(nums, reverse=True)

        # 假设可以找到和为整个数组和一半的子集, 那么剩下的就是另一个子集
        def findPartition(remain, index):
            print(index, remain)
            if remain == 0:
                return True
            if index < n and remain < nums_sort[index]:
                return False
            for i in range(index, n):
                print(index, remain, i, nums_sort[i])
                # !!! 回溯的节点, 不停的枚举试错, 一旦成功返回true
                if findPartition(remain - nums_sort[i], i + 1):
                    return True
            return False

        return findPartition(s // 2, 0)

    def canPartitionDynamic(self, nums) -> bool:
        '''
        对大牛的注释
        动态规划: 使用一维数组memo存储状态
        1. memo的索引表示数组元素子集相加可以得到的和
        2. memo的值为真: 存在和为memo索引的子集
        '''
        s = sum(nums)
        # 假设可以拆分为两个和相等的子集, 数组的和是子集和的两倍, 一定是偶数
        if s % 2 == 1:
            return False
        cnt = s // 2
        # memo的索引表示数组元素子集相加可以得到的和
        # memo的值为真: 存在和为memo索引的子集
        memo = [False] * (cnt + 1)
        for i in range(0, cnt + 1):
            memo[i] = (nums[0] == i)
        # nums[0] 为单独一个子集
        for i in range(1, len(nums)):
            # print(111, i, memo)
            for j in range(cnt, nums[i] - 1, -1):
                # j 表示子集元素和, 其中nums[i]是输入数组的元素, 肯定存在
                # !!! 若j与数组成员的差仍存在于数组, 则j是可以被组合出来的, memo设为真
                memo[j] = memo[j] or memo[j - nums[i]]
                # print(i, j, memo[j], nums[i], j - nums[i])

        return memo[cnt]


s = Solution()
print(s.canPartitionDynamic([2, 1, 3]))
# print(s.canPartitionDynamic([2, 2, 3, 5]))

```