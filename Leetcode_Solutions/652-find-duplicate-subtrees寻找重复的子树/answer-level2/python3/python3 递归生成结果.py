递归生成每个字数的序列化结果，相同的结果加入 `rootList` 中

![image.png](https://pic.leetcode-cn.com/a9db8cc920539a6ae0c2bcd0517b555bd15b90ad7c75c8c86e05f439c61930f8-image.png)

``` python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findDuplicateSubtrees(self, root: TreeNode) -> List[TreeNode]:
        self.rootList = []
        self.cache = {}
        self.stringCache = set()
        if root is None:
            return []
        self.getTreeString(root.left)
        self.getTreeString(root.right)
        return self.rootList

    def getTreeString(self, root):
        if root is None:
            return ''
        result = str(root.val)
        left = "l"+self.getTreeString(root.left)
        right = "r"+self.getTreeString(root.right)
        result = result + left + right
        if result in self.cache and result not in self.stringCache:
            self.rootList.append(root)
            self.stringCache.add(result)
        else:
            self.cache[result] = root
        return result
```

