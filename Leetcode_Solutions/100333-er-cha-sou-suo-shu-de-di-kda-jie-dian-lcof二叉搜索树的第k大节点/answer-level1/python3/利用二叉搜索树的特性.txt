### 思路
右子树-根-左子树 顺序访问二叉树

### code1
递归
```python
class Solution:
    def kthLargest(self, root: TreeNode, k: int) -> int:
        def travel(root):
            nonlocal k
            if root != None and k > 0:
                ans1 = travel(root.right)
                k = k - 1
                if k == 0: return root.val
                ans2 = travel(root.left) 
                return ans1 if ans1 else ans2
        return travel(root)
```
### code2
迭代，逆中序
```python
class Solution:
    def kthLargest(self, root: TreeNode, k: int) -> int:
        stack, node = [], root
        while len(stack) or node:
            if node:
                stack.append(node)
                node = node.right
            else:
                node = stack.pop()
                k -= 1
                if k == 0: return node.val
                node = node.left
```
