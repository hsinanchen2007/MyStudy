class Solution:
    def fourSum(self, nums: List[int], target: int) -> List[List[int]]:
        res=[]
        nums=sorted(nums)
        def dfs(start,path,nums,he,target):
            if he == target:
                res.append(path)
                if start<len(nums):
                    dfs(start+1,path+[nums[start]],nums,he+nums[start],target)
            for i in range(start,len(nums)):
                dfs(i+1,path+[nums[i]],nums,he+nums[i],target)
        dfs(0,[],nums,0,target)
        real_res=[]
        for i in res:
            if len(i)==4:
                real_res.append(i)
        z=[]
        for i in real_res:
            if i not in z:
                z.append(i)
        return z
