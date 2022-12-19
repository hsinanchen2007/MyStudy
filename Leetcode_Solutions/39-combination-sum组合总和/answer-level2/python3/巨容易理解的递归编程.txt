
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        candidates.sort()
        res_all=[]
        i=0
        def f(i,remainder,res):
            if remainder==0:
                res_all.append(res)
            elif remainder<=0:
                return

            for i in range(i,len(candidates)):
                f(i,remainder-candidates[i],res+[candidates[i]])
        f(i,target,[])
        return res_all