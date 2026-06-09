### 解题思路
定义一个字典来记录列表nums中每个元素出现的次数，计入字典
然后将字典按值逆向排序，输出前k个键

### 代码

```python3
class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        dic = {}
        for i in nums:
            if i in dic:
                dic[i] += 1
            else:
                dic[i] = 0
        res = sorted(dic.items(),key=lambda x:x[1], reverse=True)
        return [res[i][0] for i in range(k)]

```