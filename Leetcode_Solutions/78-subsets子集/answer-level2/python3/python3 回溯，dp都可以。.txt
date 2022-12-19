### 解题思路
此处撰写解题思路
典型的回溯，当然这道题目注意dp也是可以的，注释的部分就是dp部分题目。
36ms  dp
52ms  回溯方法

### 代码

```python3
class Solution:
    def subsets(self, nums: List[int]) -> List[List[int]]:
        # ans = [[]]
        # for i in range(len(nums)):
        #     temp = []
        #     if ans:                
        #         for t in ans:
        #             temp.append(t+[nums[i]])
                    
        #     ans.extend(temp)
        # return ans

        ans = [[],nums]

        def helper(nums,index,k,res):
            if k==0:
                ans.append(res[:])
            for i in range(index,len(nums)):
                res.append(nums[i])
                helper(nums,i+1,k-1,res)
                res.pop()
        
        for i in range(1,len(nums)):
            res = []
            helper(nums,0,i,res)
        return ans

```