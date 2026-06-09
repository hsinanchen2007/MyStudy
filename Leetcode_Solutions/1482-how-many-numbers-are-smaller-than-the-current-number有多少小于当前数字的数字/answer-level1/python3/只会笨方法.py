1.先排序
2.建立字典记录每个数（key）的最小位置（val）（因为可能有重复的数）
3.遍历数组查找字典
```
class Solution:
    def smallerNumbersThanCurrent(self, nums: List[int]) -> List[int]:
        tmp=nums[:]
        tmp.sort()
        d=dict()
        indx=0
        for i in tmp:
            if i not in d:
                d[i]=indx
            indx+=1    #注意这里不管在没在字典里面索引都要加一            
        res=[0]*len(nums)
        for i in range(len(nums)):
            res[i]=d[nums[i]]
        return res
```
