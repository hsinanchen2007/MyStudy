### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        dict1 = {}
        for i in nums:
            if str(i) in dict1:
                dict1[str(i)] += 1
            else:dict1[str(i)] = 1
        max_num = 0
        it = ''
        for i in dict1:
            max_num = max(max_num,dict1[i])
            if max_num == dict1[i]:
                it = i
        if max_num > len(dict1)/2:
            return int(it)
        return ''
```