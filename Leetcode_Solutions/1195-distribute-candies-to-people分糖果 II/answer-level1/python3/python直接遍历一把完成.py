考虑到有n个小朋友，c个糖果。初始化res为n个0的数组。只要还有糖果就遍历。每次对n个小朋友进行遍历。

class Solution(object):
    def distributeCandies(self, candies, num_people):
        """
        :type candies: int
        :type num_people: int
        :rtype: List[int]
        """
        res = [0]* num_people
        cand_now = 1
        while candies != 0:
            for i in range(num_people):
                cand_now = cand_now if cand_now <= candies else candies
                res[i],candies,cand_now = res[i]+cand_now,candies-cand_now,cand_now+1
        return res