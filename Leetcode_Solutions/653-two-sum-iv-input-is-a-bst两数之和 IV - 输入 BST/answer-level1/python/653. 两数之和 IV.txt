### 解题思路
从数组求和找到这来, 第一反应从二叉树取值下来双指针

```python
class Solution(object):
    def findTarget(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: bool
        """
        res = []
        res = self.findAll(root, res)
        res.sort()
        if len(res) < 2 or res[0] + res[1] > k or res[-1] + res[-2] < k:
            return False
        l = 0
        r = len(res) - 1
        while l < r:
            if res[l] + res[r] == k:
                return True
            elif res[l] + res[r] < k:
                l += 1
            elif res[l] + res[r] > k:
                r -= 1
        return False

    def findAll(self, root, res):
        if root.left:
            self.findAll(root.left, res)
        res += [root.val]
        if root.right:
            self.findAll(root.right, res)
        return res
```
**findAll**也可以这么写, 稍慢一点
```python
def findAll(self, root):
        if not root:
            return []
        return self.findAll(root.left)+[root.val]+self.findAll(root.right)
```
直接在树上哈希

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def findTarget(self, root, k):
        """
        :type root: TreeNode
        :type k: int
        :rtype: bool
        """
        return self.findAll(root, {}, k)

    def findAll(self, root, dic, k):
        if not root:
            return False
        if dic.get(k-root.val):
            return True
        else:
            dic[root.val] = 1
        return self.findAll(root.left, dic, k) or self.findAll(root.right, dic, k)
```