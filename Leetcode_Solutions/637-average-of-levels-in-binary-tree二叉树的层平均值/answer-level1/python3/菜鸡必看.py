### 解题思路
发现一个哈希表还有点不够
又生生加了个数组..

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
import collections
class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        # 用一个哈希表会更快
        res=collections.defaultdict(int)
        # 还要整个数组记录每层的节点个数
        gs=[0]*1000
        def helper(root,x) :
            nonlocal res
            nonlocal gs
            if not root :
                return 
            res[x]+=root.val
            gs[x]+=1
            helper(root.left,x+1)
            helper(root.right,x+1)
        helper(root,0)
        xww=[]
        for v in res :
            xww+=[res[v]/gs[v]]
        return xww
            
```