### 解题思路
1. 遍历得到0的index列表
2. 深度优先遍历

### 代码

```python3
class Solution:
    def canReach(self, arr: List[int], start: int) -> bool:
        marked = set()
        targetlist = []
        for index,sub in enumerate(arr):
            if sub==0:
                targetlist.append(index)

        def dfs(start,target):
            marked.add(start)
            if start in target:
                return True

            for sub in [-arr[start],arr[start]]:
                if start+sub in marked or start+sub<0  or start+sub>=len(arr): continue
                if dfs(start+sub,target):
                    return True
            
            return False

        return dfs(start,targetlist)    
```