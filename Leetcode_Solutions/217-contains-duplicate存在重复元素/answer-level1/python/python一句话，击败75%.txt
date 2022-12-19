![20200210112704.png](https://pic.leetcode-cn.com/4f7b91bb15a5bedb41f77bc9d1647ee716772db25a3a112104be98cf91b467da-20200210112704.png)

class Solution(object):
    def containsDuplicate(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """

        return False if len(list(set(nums))) == len(nums) else True

