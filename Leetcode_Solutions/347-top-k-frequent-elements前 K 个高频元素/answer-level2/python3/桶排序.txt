### 解题思路
桶排序
### 代码

```python3
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        max_times = 0
        times_dict = {}
        result = []
        for i in nums:
            times_dict[i] = times_dict.get(i,0)+1
            if times_dict[i]>max_times:
                max_times =times_dict[i]
        buckets = [[]for i in range(max_times)]
        for val,times in times_dict.items():
            buckets[times-1].append(val)
        for i in range(max_times-1,-1,-1):
            for j in buckets[i]:
                result.append(j)
                if len(result)==k:
                    return result

```