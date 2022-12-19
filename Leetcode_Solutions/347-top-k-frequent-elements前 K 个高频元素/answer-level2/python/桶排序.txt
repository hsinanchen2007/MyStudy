class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        maps = {}
        #生成字典映射
        for i in nums:
            # print('i:%d,maps.get(i,0):%d' %(i, maps.get(i,0)))
            maps[i] = maps.get(i,0) + 1
        max_time = max(maps.values())
        print(maps)
        #根据最大次数生成桶
        TongList = [[] for i in range(max_time+1)]
        for key ,value in maps.items():
            TongList[value].append(key)
            print(TongList)
        res = []
        for i in range(max_time, 0, -1):
            print('i:%d' %(i))
            if TongList[i]:
                res.extend(TongList[i])
            if len(res) >= k:
                return res[:k]
        
    
        