### 解题思路
level order 记住两个三个level，cur_level, next_level

level是最外面倒queue
cur_level是把当前level转移过来然后，开始遍历他的值for i in cur_level:
然后在把每个cur_level的值的children加到next_level里面去

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def largestValues(self, root: TreeNode) -> List[int]:

        if root is None:
            return root
        level = [root]

        res = []

        while level:
            cur_level = level
            next_level = []
            max_num = float('-inf')
            for i in cur_level:
                max_num = max(i.val, max_num)
                if i.left:
                    next_level.append(i.left)
                if i.right:
                    next_level.append(i.right)

            res.append(max_num)
            level = next_level

        return res
```