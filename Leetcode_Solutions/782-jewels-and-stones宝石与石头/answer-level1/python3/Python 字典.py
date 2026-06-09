class Solution:
    def numJewelsInStones(self,J, S):
        harshmap = {}
        res = 0
        for item in J :
            harshmap[item] = 0
        for item in S :
            if harshmap.get(item) is not None:
                harshmap[item] += 1
        for item in harshmap:
            res += harshmap[item]
        return res
设置一个字典，存放是宝石，默认值为0，然后遍历数组S ，如果S中的数据在字典中存在，对应的数据位的值+1，最后遍历字典 对数据位求和。