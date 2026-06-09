一开始绕到DP里面去了，越想越难，于是开始小数字做实验，然后被0干扰了...
然后发现0特殊，直接单独搞出来...
从 0， 1  2^1开始做实验总结规律，
然后开始做01， 10， 11，这种2^2这种，考虑博弈论里面先后手的互相转换关系..
于是...

class Solution(object):
    def xorGame(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        count_0 =  len([0 for i in nums if i == 0])
        nums = [i for i in nums if i != 0]
        t = 0
        for i in nums:
            t = t ^ i
        if t == 0:
            return True

        res = True
        if len(nums) % 2 == 1:
            res = False
        if count_0 % 2 == 1:
            res = (not res)
        return res