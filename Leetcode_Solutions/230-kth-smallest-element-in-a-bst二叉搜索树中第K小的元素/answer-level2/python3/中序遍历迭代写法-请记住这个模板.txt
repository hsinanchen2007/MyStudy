![image.png](https://pic.leetcode-cn.com/f93c6b91041e341658347e3f92dbadc6ddaec2e9b6fe07a1d4912c8c89825ef5-image.png)


```python
class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        stack= []
        counter = 0
        while len(stack)>0 or root is not None:
            if root is not None:
                stack.append(root)
                root = root.left
            else:
                root = stack.pop()
                counter += 1
                if counter==k:
                    break

                root = root.right

        return root.val
```