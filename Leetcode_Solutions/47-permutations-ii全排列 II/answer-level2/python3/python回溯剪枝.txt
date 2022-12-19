```
class Solution:
    def permuteUnique(self, nums):
        """
        给定包含重复数字的序列，给出其全排列
        :param nums:给定的包含重复数字的序列
        :return:全排列
        """
        if len(nums) <= 1:
            return [nums]

        answer_list = []
        answer = []
        flag = [False for i in range(0, len(nums))]

        def _find():
            """
            递归查找所有的排列
            :return:
            """
            if len(answer) == len(nums):
                answer_list.append(answer.copy())
                return

            nums_set = set()
            for i in range(0, len(nums)):
                # 这个数字为未选过且这个数字没在当前的位置出现过（剪枝：一种数字一个位置只需要出现一次）
                if flag[i] is False and nums[i] not in nums_set:
                    answer.append(nums[i])
                    flag[i] = True
                    nums_set.add(nums[i])
                    _find()
                    answer.pop()
                    flag[i] = False

        _find()
        return answer_list
```
