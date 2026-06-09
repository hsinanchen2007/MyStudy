`class Solution(object):
    def distributeCandies(self, candies):
        """
        :type candies: List[int]
        :rtype: int
        """

        return len(set(candies)) if len(set(candies)) < len(candies)/2 else len(candies)/2

        '''
        #遍历的方法超时了   150 / 205 个通过测试用例
        species = 0
        li = []
        n = len(candies)
        for candy in candies:
            if candy not in li and species < n/2 and len(li) <n/2:
                li.append(candy)
                species += 1
        return species
        '''
`