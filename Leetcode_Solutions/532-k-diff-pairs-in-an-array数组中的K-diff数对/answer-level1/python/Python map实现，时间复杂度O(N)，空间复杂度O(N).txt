    def findPairs(self, nums, k):
        dic, res = {}, 0
        for i in nums: dic[i] = dic.get(i, 0) + 1
        # 遍历一遍生成map
        if k < 0: return 0
        # k小于0，不合题意，直接返回0
        elif k == 0: 
            values = dic.values()
            for i in values: 
                if i >= 2: res += 1
        # k等于0，遍历map中value大于等于0的值，返回总数
        else:
            for i in set(nums):
                if dic.get(i + k): res += 1
        # k大于0，先用set去重，遍历一遍找绝对值相差k的值
        return res