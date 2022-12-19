
### 1.分析

看到中序遍历和后序遍历就要先考虑它们的遍历形式：
`中序：左根右， 后序：左右根`
那么就能想到可以通过后序的`-1`元素得知`root`的值，然后通过`root`的值去前序数组里找到左右子树的数组，并且也能拆分后序数组，获得左右子树的后序遍历结果，依次递归下去：

base case就是如果没有节点，那么`return None`，返回的值是`TreeNode`

![image.png](https://pic.leetcode-cn.com/efbfaa3ded7038a9b91cafcded5e56afc782143b541bb9c91c75f838b1233df7-image.png)

```
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        if not inorder:
            return
        
        val = postorder[-1]
        index = inorder.index(val)
        
        root = TreeNode(val)
        root.left = self.buildTree(inorder[:index], postorder[:index])
        root.right = self.buildTree(inorder[index+1:], postorder[index:-1])
    
        return root
```
