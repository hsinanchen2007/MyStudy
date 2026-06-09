**此题中等难度在于最后要将【3，【9，20】，【15，7】】变为【3，9，20，15，7】**
**教你如何区分append和extend！**
**如给定一个[[],[],[]]，append的结果即为 [[3],[9，20],[15，7]]，而extend的结果即为[3，9，20，15，7]!
所以此题最后用extend就行了！**
```
class Solution:
    def levelOrder(self, root: TreeNode) -> List[int]:
        if not root: return 
        res = []
        def dfs(node, level):
            if not node: return
            if level == len(res):
                res.append([])
            res[level].append(node.val)
            if node.left: dfs(node.left, level + 1)
            if node.right: dfs(node.right, level + 1)
        dfs(root, 0)
        final_res=[]
        for i in res:
            final_res.extend(i)
        return final_res
```
