```
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        '''
        #思路1：python库函数：itertools.combinations(iterable, r)
        res=[]
        res.append([]) #一定有[]
        size=len(nums)
        for i in range(1,size+1):
            mid = itertools.combinations(nums,i)
            for item in mid:
                res.append(list(item))
        return res
        '''
        
        #思路2：回溯
        res=[]
        res.append([])
        nums = sorted(nums)
        def helper(midNums,tmp,k):
            if(k==0):
                res.append(tmp)
                return
            for j in range(len(midNums)):
                helper(midNums[j+1:],tmp+[midNums[j]],k-1)
        
        if(len(nums) == 0):
            return []
        elif(len(nums) == 1):
            res.append(nums)
            return res
        else:
            for index in range(1,len(nums)+1):
                helper(nums,[],index)
            return res
```
