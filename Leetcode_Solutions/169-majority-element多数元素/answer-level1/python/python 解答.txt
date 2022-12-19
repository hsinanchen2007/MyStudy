### 解题思路
此处撰写解题思路

### 代码

```python3
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        c=dict.fromkeys(nums,0)#对字典key值进行统计
        for one in nums:#key是列表值，value是统计次数
            c[one]+=1
        cf =max(c,key=c.get)# 输出字典中value中最大的值
        return cf
```