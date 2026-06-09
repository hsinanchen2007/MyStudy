### 解题思路
[@mian-mian-sir](/u/mian-mian-sir/)
参看大佬，做了些许改动

### 代码

```python
class Solution:
# 加入初始化
    def __init__(self):
        self.maxvalue=0
    def maxAncestorDiff(self, root: TreeNode) -> int:
        self.dfs(root,0,100001)
        return self.maxvalue
#整体思路相当于dfs那一条线上的最大最小值的一个差值，和全局插值做对比    
    def dfs(self,node,maxv,minv):
        if not node:
            self.maxvalue = max(maxv-minv, self.maxvalue)
        else:
            maxv, minv = max(maxv,node.val), min(minv,node.val)
            self.dfs(node.left,maxv,minv)
            self.dfs(node.right,maxv,minv)  

```