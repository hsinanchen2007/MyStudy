### 解题思路
此处撰写解题思路

### 代码

```python
class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        i = 0
        for j in range(1,len(nums)):
            if nums[j] != nums[i]: #一直是保持不变，终于变了，放在不变的
                nums[i+1] = nums[j] #将 j = 2 的位置上的数，放 i= 0+1 处
                i+=1
        return i+1
```
先设置初始位置指向i=0，然后让nums从1到最后开始循环，如果遇见与nums[i]位置相同的数，则放任不管，遇见不相同的数，就将其值，即nums[j]赋给初始位置的下一位，也就是i+=1位，最后为啥返回return i+1 没搞清楚