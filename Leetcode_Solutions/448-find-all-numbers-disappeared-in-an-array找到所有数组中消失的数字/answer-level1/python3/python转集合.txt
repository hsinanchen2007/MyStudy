```
class Solution(object):
    def findDisappearedNumbers(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """

        n = len(nums)
        s_num = set(nums)
        s_perfect = set([i for i in range(1, n + 1)])
        return list(s_perfect - s_num)

```
