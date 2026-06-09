### 解题思路
此处撰写解题思路

### 代码
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        b={}#定义空字典
        for d in set(nums):#去重复的值，set
            b[nums.count(d)]=d#去重后做计数，把数量和值写到字典b
        for e in reversed(sorted(b.keys())[-1:]): #排序列表键值并取后1个
            return b[e]



```