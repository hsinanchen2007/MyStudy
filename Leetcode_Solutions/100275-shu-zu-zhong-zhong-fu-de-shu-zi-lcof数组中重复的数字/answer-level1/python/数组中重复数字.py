### 解题思路
此处撰写解题思路
  利用哈希结构（字典）解决这个问题，从头到尾扫描这个数组。如果字典中存在这个数字，则返回该值，
如果不存在，则加入字典
### 代码

```python3
class Solution:
    def findRepeatNumber(self, nums: List[int]) -> int:

        dict={}
        if len(nums)==0:
            return False
        for i in nums:
            if i in dict:
                return i
            dict[i]=1
        return False
```