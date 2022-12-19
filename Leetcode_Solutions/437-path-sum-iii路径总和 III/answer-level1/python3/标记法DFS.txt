### 解题思路
我是连暴力递归法都要想好久的那类人；所以这个解也只能给和我一样的同学参考一下当active标记是关闭的时候，表示当前是从之前节点经过的路径，并不开启这个节点的dfs过程。（即只有这个节点的父节点才能开启它！）
其实如果树里没有负数那就不用这个标记了，只用now==0判断就行，但树里不光有负数还有0节点，那就没办法了；（没负数早就剪枝过了
我也说不太清楚啦 hhh。

### 代码

```python3

class Solution:
    def pathSum(self, root: TreeNode, s: int) -> int:
        
        res = 0
        tar = s

        def dfs( node, cur, active) -> None:
            nonlocal res, tar
            if not node:
                return 
            now = cur + node.val
            if now == tar:
                res += 1
            
            if active:
                dfs( node.left, 0, True)
                dfs( node.right, 0, True)
            dfs( node.left, now, False)
            dfs( node.right, now, False)
            
        
        dfs(root, 0, True)
        
        return res
```