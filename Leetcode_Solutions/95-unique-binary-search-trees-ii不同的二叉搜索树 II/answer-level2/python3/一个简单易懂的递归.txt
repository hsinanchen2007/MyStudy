n个数的所有树，基于n-1的树的结果，对n-1的树中每个树，再做一次遍历
遍历只往右子树遍历，可以在当前节点和其右子节点之间插入节点n，每遍历到一个位置插入就是一个n节点数

框架：
```
if n == 0 
    do
if n == 1:
    do
else:
    res = []
    res_n_1 = 递归(n-1)
    for tree in res_n_1:
        while tree: # 向右遍历tree
            在每个tree节点之后插入值为n的节点（tree的右子树挂到新的n节点左边，然后n节点挂到tree的右边），这就是一个n节点树
            res.append(上一步的n节点树)
    return res

```

代码效率一般，因为要修改树，需要引入copy 模块，要复制很多完整的树，空间开销偏大，优点是思路很容易理解

```
import copy

class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        if n == 0:
            return []
        elif n == 1:
            return [TreeNode(1)]
        else:
            res = []
            res_n_1 = self.generateTrees(n-1)
            for tree in res_n_1:
                p = TreeNode(-1)
                p.right = tree
                while p:
                    tmp_head = tmp_p = TreeNode(-1)
                    tmp_p.right = copy.deepcopy(tree)
                    while tmp_p.val != p.val:
                        tmp_p = tmp_p.right
                    node_n = TreeNode(n)
                    node_n.left = tmp_p.right
                    tmp_p.right = node_n
                    res.append(tmp_head.right)
                    p = p.right
            return res
                        
```
