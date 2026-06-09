### 解题思路
与第257题思路几乎相同,利用栈,将每一条路径都遍历

### 代码

```python3
class Solution:
    def sumNumbers(self, root: TreeNode) -> int:
        if not root:
            return 0
        stack=[(root,str(root.val))]
        res=[]#存储每一条路径的数
        while stack:
            node,val=stack.pop()#node表示返回的节点,val表示路径
            if not node.right and not node.left:
                res.append(val)
            if node.right:#如果右子树存在
                stack.append((node.right,val+str(node.right.val)))
            if node.left:#如果左子树存在
                stack.append((node.left,val+str(node.left.val)))
        sus=sum(int(i)for i in res )#遍历res,求和
        return sus
```