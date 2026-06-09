#用字典和列表的转化，以及循环，是非常容易的


class Solution:
    def majorityElement(self, nums: List[int]) -> List[int]:
        nums.sort()
        dic = {}
        li = []
        for i in nums:
            if i in dic:
                dic[i] += 1
            else:
                dic[i] = 1

        for item in dic:
            if dic[item] > int(len(nums)/3):
                li.append(item)
        return li