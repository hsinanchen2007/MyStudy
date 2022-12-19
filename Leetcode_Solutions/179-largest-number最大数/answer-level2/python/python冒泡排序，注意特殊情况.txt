### 解题思路
1.冒泡排序
2.注意特殊情况，当nums[0]==0的时候，直接返回字符串"0",比如[0,0,0],结果返回"0"

### 代码

```python
class Solution(object):
    # 冒泡排序：
    def largestNumber(self, nums):
        """
        :type nums: List[int]
        :rtype: str
        """
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                a=str(nums[i])+str(nums[j])
                b=str(nums[j])+str(nums[i])
                if a<b:
                    nums[i],nums[j]=nums[j],nums[i]
        if nums[0]==0:
            return "0"
        res=""
        for i in range(len(nums)):
            res=res+str(nums[i])
        return res


```