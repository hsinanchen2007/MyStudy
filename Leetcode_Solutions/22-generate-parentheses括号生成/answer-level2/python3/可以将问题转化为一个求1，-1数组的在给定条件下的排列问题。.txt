1、如果把'('看作1，')'看作-1，根据解是否为有效括号的思想加入（我们就+1，加入）我们就-1，始终保持数为正数，这为求全排列的限制条件
2、再根据求有重复值的全排列问题的思想，限制当nums[j]==nums[j-1]时就直接继续，则其实问题就已经转化为求全排列问题

```
class Solution:
    def generateParenthesis(self, n: int) -> List[str]:
        if n<=0:
            return []
        nums=['(']*n+[')']*n  
        res=[]
        def helper(nums,tmp,m):  #这里nums是我们求全排列的数组，tmp是每次加入的结果列表的一个合理答案，m是要始终保持大于等于0
            if not nums:
                return res.append(tmp)
            for j in range(len(nums)):
                if m<0:
                    break
                if j>0 and nums[j-1]==nums[j]:
                    continue
                helper(nums[:j]+nums[j+1:],tmp+nums[j],m-1 if nums[j]==')' else m+1) #注意这里nums每次实际上是减少了一个元素的
        helper(nums,'',0)
        return res
```

