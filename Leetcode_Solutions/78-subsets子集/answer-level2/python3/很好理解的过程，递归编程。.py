    def subsets(self, nums: List[int]) -> List[List[int]]:
        nums.sort()

        nums.append('end')

        res_all=[]
        k=0

        def f(k,res):
            if len(res)==len(nums)-1:
                res_all.append(res)
                return

            for i in range(k,len(nums)):
                if nums[i]=='end':
                    res_all.append(res)
                    return
                else:
                    f(i+1,res+[nums[i]]) #这里很i+1很巧妙，可以理解下。

        f(k,[])
        return res_all