### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def findShortestSubArray(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # 用hashmap 找频数最大的数字
        hashmap = {}
        for i in range(len(nums)):
            if nums[i] not in hashmap:
                hashmap[nums[i]] = 1
            else:
                hashmap[nums[i]] += 1

        # 寻找出现最大次数
        max_times = max(hashmap.values())

        # 找到最大次数对应的值
        ret_list = []
        for k, v in hashmap.items():
            if v == max_times:
                ret_list.append(k)
        
        # 遍历数组，找最短的长度
        result = 500001
        for target in ret_list:
            min_index = 500001
            max_index = 0
            for j in range(len(nums)):
                if nums[j] == target:
                    if j < min_index:
                        min_index = j
                    if j > max_index:
                        max_index = j
            if result > max_index - min_index:
                result = max_index - min_index + 1
        return result

        
```