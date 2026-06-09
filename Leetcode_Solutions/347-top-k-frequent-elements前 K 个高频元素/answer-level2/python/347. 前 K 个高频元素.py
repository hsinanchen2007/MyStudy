### 解题思路
第一步：用字典统计每个数字出现的频率
第二步：根据字段中的value降序排序
第三步：输出前 K 个高频元素
### 代码

```python
class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        if not nums:
            return None
        
        res = list()
        dic = dict()

        for i in range(len(nums)):
            if nums[i] not in dic:
                dic[nums[i]] = 1
            else:
                dic[nums[i]] += 1

        dic = sorted(dic.items(), key=lambda x: x[1], reverse=True)

        for i in range(k):
            res.append(dic[i][0])

        return res
```