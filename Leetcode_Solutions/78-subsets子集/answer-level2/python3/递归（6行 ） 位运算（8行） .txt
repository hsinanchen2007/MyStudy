递归的想法就是将问题分解为更小的问题。n个数字的组合划归为n-1个数字的组合+[n]。感觉比DFS加上路径好理解
```
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        if not nums: return [[]]
        res=[] 
        for p in self.subsets(nums[1:]):
            res.append(p) # 把子集加上
            # print(nums[:1]+p)
            res.append(nums[:1]+p) 
        return res
```
使用位运算，对每一位为1的表示这一位的数字存在，例如对于输入[1,2,3] 编码i=001，表示只含有3，编码i=101.表示含有1,3
```
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        t=len(nums)
        res=[]
        for i in range(2**t):
            tmp=[]
            for j in range(t):
                if i&(1<<j):tmp.append(nums[t-1-j])
            res.append(tmp)
        return res
```