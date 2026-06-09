### 解题思路
**1.递归**
参考官方题解

### 代码
```python
class Solution(object):
    def binaryTreePaths(self, root):
        if not root:return []
        def subtree(root,cur):
            if root:
                cur += str(root.val)
                children = [root.left,root.right]
                if not any(children):
                    ans.append(cur)
                else:
                    cur += '->'
                    subtree(root.left,cur)
                    subtree(root.right,cur)
        ans = []
        cur = ''
        subtree(root,cur)
        return ans
```
### 解题思路
**2.迭代**

### 代码
```python
class Solution(object):
    def binaryTreePaths(self, root):
        if not root:return []
        ans = []
        cur = ''
        stack = [(root,cur)]
        while stack:
            root,cur = stack.pop()
            if root:
                cur += str(root.val)
                children = [root.left,root.right]
                if not any(children):
                    ans.append(cur)
                else:
                    if root.left:
                        stack.append((root.left,cur + '->'))
                    if root.right:
                        stack.append((root.right,cur + '->'))
        return ans
```