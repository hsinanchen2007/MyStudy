```
class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        map = {}
        for i in nums:
            map[i] = map.get(i,0) + 1    #生成字典映射
            
        max_time = max(map.values())
        
        #根据最大次数生成桶
        bucket_list = [[] for i in range(max_time+1)] 
        
        for key, value in map.items():
            #将索引value放入key对应的字典索引
            bucket_list[value].append(key) 
            
        res = []
        #按桶索引排序
        for i in range(max_time, 0, -1): 
            if bucket_list[i]:
                res.extend(bucket_list[i])
            if len(res) >= k:
                return res[:k]

        
        
    def top_k_freq(self,nums,k):
        res = []
        heap_max = []
        record_dict = {}
        for num in nums:
            if num not in record_dict:
                record_dict[num] = 1
            else:
                record_dict[num] +=1
                
        # 遍历 将所有的元素都加入堆中，这里需要使用负值
        for key in record_dict:
            heapq.heappush(heap_max,(-record_dict[key],key))
        
        #获取前K高频
        for _ in range(k):
            p = heapq.heappop(heap_max)
            res.append(p[1])
        return res
```



