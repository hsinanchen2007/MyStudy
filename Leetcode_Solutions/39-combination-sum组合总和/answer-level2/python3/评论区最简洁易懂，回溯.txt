class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        self.res=[]

        def dfs(candidates,path):
            if sum(path)>target:#大了就返回
                return 
            if sum(path)==target:#等于就加入
                self.res.append(path[:])
            for i in range(len(candidates)):
                path.append(candidates[i])
                dfs(candidates[i:],path)#每次数组都从i开始去重
                path.remove(candidates[i])
        dfs(candidates,[])
        return self.res