思路一：利用字典，如果在字典中不存在元素i则添加i至字典 如果i存在在字典中则返回i

```
class Solution(object):
    def findRepeatNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        # from collections import defaultdict
        dic={}
        for i in nums:
            if i not in dic:
                dic[i]=1
            else:
                return i
```

