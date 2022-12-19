直接循环整数，没出现在数组中就返回
class Solution:
    def firstMissingPositive(self, nums):
        n = 1
        while(n):
            if(n in nums):
                n+=1
            else:
                return n