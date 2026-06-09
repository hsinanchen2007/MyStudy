class Solution:
    def threeSumClosest(self, nums: List[int], target: int) -> int:
        res=[]
        d={}
        if len(nums)<3:
            return
        def dfs(nums,path):
            if len(path)==3:
                res.append(path)
                return
            for i in range(0,len(nums)):
                dfs(nums[i+1:],path+[nums[i]])
        dfs(nums,[])
        for i in range(len(res)):
            d[abs(target-sum(res[i]))] = res[i]
        d= sorted(d.items())
        return sum(d[0][1])