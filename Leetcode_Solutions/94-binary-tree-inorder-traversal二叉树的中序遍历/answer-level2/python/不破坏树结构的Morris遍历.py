

```
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:#看到后面一题前序遍历的不破坏结构的莫里斯遍历之后重新回来写的
        pre=None
        current=root
        result=[]
        while current:
            if not current.left:
                result.append(current.val)
                current=current.right
            else:
                pre=current.left
                while pre.right and pre.right is not current: 
                    pre=pre.right
                if not pre.right:
                    pre.right=current
                    current=current.left
                else:
                    result.append(current.val)
                    current=current.right
                    pre.right=None
        return result
```
        