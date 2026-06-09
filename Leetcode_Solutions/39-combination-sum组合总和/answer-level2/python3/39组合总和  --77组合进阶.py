### 解题思路
组合 - 回溯：
排好序后，顺序输入，像77组合 一样不用visited数组。
#### 递归基：
在某个节点处`target==0`，记录res
#### 递归：
1.减枝条件：若当前节点值<0,直接退出
2.由于允许重复元素，下一层的节点搜索位置从`i`开始

### 代码

```python3
class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        #组合-回溯
        if len(candidates)==0:return []
        candidates.sort()
        path=[]
        res=[]
        start=0
        def DFS(start,path,res,target):
            if target==0:#依次相减，减到0返回
                res.append(path[:])
                return
            for i in range(start,len(candidates)):
                #剪枝:在某一层节点值已小于0，则直接退出
                if target-candidates[i]<0:break
                path.append(candidates[i])
                DFS(i,path,res,target-candidates[i])#下一个start=i
                path.pop()
        DFS(start,path,res,target)
        return res
```