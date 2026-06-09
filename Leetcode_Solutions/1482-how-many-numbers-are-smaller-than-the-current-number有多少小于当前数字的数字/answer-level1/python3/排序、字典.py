### 解题思路
此处撰写解题思路:
1. 排序 
2. 记录字典
3. 输出结果
![image.png](https://pic.leetcode-cn.com/80617f203c2e1d3e473bfa85ec094601de864b685e0812b6490f8d6212e06b03-image.png)

### 代码

```python3

class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        tmpnumsdict = {}
        tmpnums = nums[:]
        tmpnums.sort()
        for index, item in enumerate(tmpnums):
            if index == 0:
                tmpnumsdict[item] = 0
            elif tmpnums[index] == tmpnums[index -1]:
                continue
            else:
                tmpnumsdict[item] = len(tmpnums[:index])
        smallerlist = []
        for item in nums:
            if item in tmpnumsdict:
                smallerlist.append(tmpnumsdict[item])
        return smallerlist
        


```