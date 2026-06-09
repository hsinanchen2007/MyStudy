### 解题思路
以为有什么难度呢，结果一个集合就搞定了😭

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class FindElements:

    def __init__(self, root: TreeNode):
        self.ans = []
        if not root:
            return
        root.val = 0
        self.res = [root]
        while self.res:
            a = self.res.pop(0)
            self.ans.append(a.val)
            if a.left:
                a.left.val = a.val * 2 + 1
                self.res.append(a.left)
            if a.right:
                a.right.val = a.val * 2 + 2
                self.res.append(a.right)
        

    def find(self, target: int) -> bool:
        left = 0
        right = len(self.ans) - 1
        while left <= right:
            mid = (left + right)>>1
            if self.ans[mid] == target:
                return True
            elif self.ans[mid] < target:
                left = mid + 1
            elif self.ans[mid] > target:
                right = mid - 1
        return False
        


# Your FindElements object will be instantiated and called as such:
# obj = FindElements(root)
# param_1 = obj.find(target)
```