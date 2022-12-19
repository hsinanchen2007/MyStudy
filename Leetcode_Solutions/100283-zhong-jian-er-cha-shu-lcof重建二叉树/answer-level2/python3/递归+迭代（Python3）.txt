
### 代码

```python []
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        if len(inorder) == 0:
            return None
        
        # 根节点
        root = TreeNode(preorder[0])
        # 获取根节点在 inorder 中的索引
        idx = inorder.index(preorder[0])
        # 左子树
        root.left = self.buildTree(preorder[1:idx+1], inorder[:idx])
        # 右子树
        root.right = self.buildTree(preorder[idx+1:], inorder[idx+1:])
        return root

```
```python []
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        """思路为官方题解的迭代法思路，注意每次遍历比较的是什么，一定要在纸上模拟一遍，不要光想"""
        if not preorder:
            return None
            
        root = TreeNode(preorder[0])
        stack = []
        L = len(preorder)
        stack.append(root)
        index = 0

        for i in range(1, L):
            preorderval = preorder[i]
            if inorder[index] != stack[-1].val: # 比较栈顶元素和inorder
                node = stack[-1]
                node.left = TreeNode(preorderval)
                stack.append(node.left)
            else:
                while stack and stack[-1].val == inorder[index]:
                    node = stack[-1]
                    stack.pop()
                    index += 1
                node.right = TreeNode(preorderval)
                stack.append(node.right)
        return root
```
