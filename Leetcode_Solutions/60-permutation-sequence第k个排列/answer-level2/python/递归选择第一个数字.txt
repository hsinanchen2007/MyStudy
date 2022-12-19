```
class Solution:
    def getPermutation(self, n: int, k: int) -> str:
        ##计算阶乘
        def fac(m):
            res=1
            for i in range(1,m+1):
                res*=i
            return res
        nums=list(range(1,n+1))

        def get_perm(nums,k,pre):
            ##递归终止条件
            if len(nums)==1:
                return pre+[nums[0]]
            ##选择一个数字，有了n_root种方案，去掉已选数字后剩余数字有fac(n_root-1)种组合
            n_root=len(nums)
            n_leaves_per_root=fac(n_root-1)
            ##计算应该选择哪个数字
            nth_root=k//n_leaves_per_root
            ##计算选择这个数字后，剩下的数字组合位于除该数字外剩余数字组合的第几个
            nth_leaf=k%n_leaves_per_root
            return get_perm(nums[:nth_root]+nums[nth_root+1:],nth_leaf,pre+[nums[nth_root]])
        #k转换为从0计数
        res=get_perm(nums,k-1,[])
        return ''.join([str(i) for i in res])
```
