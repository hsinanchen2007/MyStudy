
代码块
```
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        map = {}
        for i in nums:
            map[i] = map.get(i,0) + 1    #生成字典映射
        max_time = max(map.values())
        TongList = [[] for i in range(max_time+1)] #根据最大次数生成桶
        for key, value in map.items():
            TongList[value].append(key) #将索引value放入key对应的字典索引
        res = []
        for i in range(max_time, 0, -1): #按桶索引排序
            if TongList[i]:
                res.extend(TongList[i])
            if len(res) >= k:
                return res[:k]
```

