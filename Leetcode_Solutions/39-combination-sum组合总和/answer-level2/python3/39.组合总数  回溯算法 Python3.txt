大体思路：每一次不停的试探将candidates中的元素放入now中，now列表中元素的总和为cur,判别条件是cur==target则找到一个正确解并存入res中，要是cur的值已经超过target，说明这条路不通，向上回溯一步（取出刚刚放入now中的元素并球新的cur的值）
**代码一有问题**，会跑出重复的结果[[2,2,3],[2,3,2],[3,2,2],[7]]
```
class Solution:#代码一
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def dfs(candidates,cur,now,res,target):
            if cur==target:
                res.append(now.copy())
                return
            elif cur>target:
                return False
            else:
                for i in candidates:
                    cur=cur+i
                    now.append(i)
                    dfs(candidates,cur,now,res,target)
                    now.pop()
                    cur=cur-i   
                    
        res=[]
        dfs(candidates,0,[],res,target)
        return res
```
原因是深层的元素会引用浅层的元素造成重复，所以应该提前进行排序，并且加入path参数记录深度，在for循环遍历时只遍历（path,size）之间的元素，避免重复，**代码二正确**
```
class Solution:#代码二
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        def dfs(candidates,cur,now,res,target,path,size):
            if cur==target:
                res.append(now.copy())
                return
            elif cur>target:
                return False
            else:
                for i in range(path,size):
                    cur=cur+candidates[i]
                    now.append(candidates[i])
                    dfs(candidates,cur,now,res,target,i,size)
                    now.pop()
                    cur=cur-candidates[i]   
                    
        res=[]
        size=len(candidates)
        candidates.sort()
        dfs(candidates,0,[],res,target,0,size)
        return res
```
同理40题组合总数和||中多了一个元素在一个解中只能出现一次的条件，并且不能有重复
在代码二中增加一句即可
```
class Solution:#代码二
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        def dfs(candidates,cur,now,res,target,path,size):
            if cur==target:
                res.append(now.copy())
                return
            elif cur>target:
                return False
            else:
                for i in range(path,size):
                    #if i>path and candidates[i]==candidates[path]:  #!!注意此句是错误的，因为path可能不等于i-1
                    if i>path and candidates[i]==candidates[i-1]:  #此句正确，可以达到去重的效果
                        continue
                    cur=cur+candidates[i]
                    now.append(candidates[i])
                    dfs(candidates,cur,now,res,target,i,size)
                    now.pop()
                    cur=cur-candidates[i]   
                    
        res=[]
        size=len(candidates)
        candidates.sort()
        dfs(candidates,0,[],res,target,0,size)
        return res
```