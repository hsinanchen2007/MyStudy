![image.png](https://pic.leetcode-cn.com/c95bd3569de9d0b66f3af0b1540ad0c2406001f1ec8a179aab302821230c2ee3-image.png)



```
'''
dfs 同时维护到达当前位置的路径即可，比较路径的尾部和目标序列是否一致
'''

class Solution:

    def dfs(self, root, path, target):
        if root is None:
            return False

        path.append(root.val)
        if len(path) >= len(target) and target == path[-len(target):]:
            return True

        ans = self.dfs(root.left, path, target) or self.dfs(root.right, path, target)
        path.pop(-1)
        return ans

    def isSubPath(self, head: ListNode, root: TreeNode) -> bool:
        target = []
        while head:
            target.append(head.val)
            head = head.next

        return self.dfs(root, [], target)
```
