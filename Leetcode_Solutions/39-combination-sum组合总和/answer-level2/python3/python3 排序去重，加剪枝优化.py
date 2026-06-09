### 解题思路
此处撰写解题思路
排序去重复，剪枝的化，这里是如if语句所示，排好序，减法做的小于0之后的就不用递归了，选择下标开始的地方，不可以选择小于上一层的下标开始的地方
和之前的那个有重复字符串的排列组合一样，这里回溯注意的就是 开始的下标需要动态更新。
### 代码

```python3
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        
        ans = []
        candidates.sort()
        size = len(candidates)
        def helper(c,index,t,res):
            if t==0:                
                ans.append(res[:])
                return 
            for i in range(index,size):
                if t-candidates[i]<0:
                    break
                res.append(candidates[i])                
                helper(c,i,t-candidates[i],res)
                res.pop()
        helper(candidates,0,target,[])
        return ans
```