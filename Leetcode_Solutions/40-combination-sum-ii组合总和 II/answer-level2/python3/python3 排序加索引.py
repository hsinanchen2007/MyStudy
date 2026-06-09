### 解题思路
此处撰写解题思路
典型的排序，以及candidates选择下标设置去重。

### 代码

```python3
class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:

        candidates.sort()
        n = len(candidates)
        ans = []

        def helper(c,index,t,res):
            if t==0:
                ans.append(res[:])
                return
            pre = 0
            for i in range(index,n):

                if t-c[i]<0:
                    break
                if c[i]!=pre:
                    res.append(c[i])
                    helper(c,i+1,t-c[i],res)
                    res.pop()
                pre = c[i]
        
        helper(candidates,0,target,[])
        return ans
```