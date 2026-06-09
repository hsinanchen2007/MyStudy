### 解题思路
1.把所有i+value都放入index[]中
2.每一步都找到最大长度
3.如果最大长度大于len(nums)-1,那么跳出计数
max_index=max(indexs[pre_max_index:max_index+1])#11
为了优化时间，找对应切割
### 代码

```python
class Solution(object):
    def jump(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums)<2:
            return 0
        indexs=[]
        for i,value in enumerate(nums):
            indexs.append(i+value)
        max_index=indexs[0]#5
        count=1
        pre_max_index=0
        while(max_index<len(nums)-1):
                another=max_index
                #print(pre_max_index,max_index)
                max_index=max(indexs[pre_max_index:max_index+1])#11
                pre_max_index=another
                count+=1         
        return count






```