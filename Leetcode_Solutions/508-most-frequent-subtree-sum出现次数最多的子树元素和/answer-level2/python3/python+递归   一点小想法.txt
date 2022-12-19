### 解题思路
    参考了小bear的代码，但做了一些修改，这里的path不需要用self.path或者在函数中作为参数传入，因为path里的值不需要弹出，没有修改，只有单纯的添加新的值进去，值本身在递归过程是不变的。
    还有if not root: return 0已经包含叶节点的情况（叶节点再递归一次就得到了），不需要额外判断。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findFrequentTreeSum(self, root: TreeNode) -> List[int]:
        if not root: return []
        path = []
        def helper(root):
            if not root: return 0
            l = helper(root.left)
            r = helper(root.right)
            s = l + r + root.val
            path.append(s)
            return s
        helper(root)
        d = collections.Counter(path)
        max_num = max(d.values())
        res =[]
        for i in d:
            if d[i] == max_num:
                res.append(i)
        return res

        
```