算法思想：
1、未遍历的节点，标记为白色，已遍历的标记为灰色
2、后序遍历，左>右>根，因此基于栈的先入后出的原则，先压入标记为灰色的根节点，再压入标记为白色的右子树节点，最后压入标记为白色的左子树节点
3、若遍历到灰色节点，则加入输出的结果数组中

```
def postorderTraversal(self, root):
        """
        :type root: TreeNode
        :rtype: List[int]
        """
        if not root:
            return
        res = []
        stacks = [("white",root)]
        while len(stacks)>0:
            color,node = stacks.pop()
            if color == 'white':
                stacks.append(('gray',node))
                if node.right:
                    stacks.append(('white',node.right))
                if node.left:
                    stacks.append(('white',node.left))
            else:
                res.append(node.val)
        return res
```
