这个题实在太简单了吧
因为给出的是最大前进步数，一个子数组，如果没有0，那就必定能走到所有位置以及其后的一个位置
所以只要找0，然后看这个位置能不能达到，能行就赋值1，直到没有0或者不能达到，代码极其简单


class Solution:
    def canJump(self, nums: List[int]) -> bool:
        nums = nums[0:-1]
        while 0 in nums:
            index_0 = nums.index(0)
            for iter in range(index_0 - 1, -1, -1):
                if nums[iter] > index_0 - iter:
                    nums[index_0] = 1
                    break

            if nums[index_0] == 0:
                return False
        return True



执行用时 :
32 ms
, 在所有 Python3 提交中击败了
99.66%
的用户
内存消耗 :
15 MB
, 在所有 Python3 提交中击败了
7.84%
的用户