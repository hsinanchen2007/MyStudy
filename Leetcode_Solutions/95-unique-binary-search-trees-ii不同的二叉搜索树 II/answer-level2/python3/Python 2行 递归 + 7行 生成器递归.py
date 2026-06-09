```python
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x, l=None, r=None):
        self.val = x
        self.left = l
        self.right = r

class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        def gen(num): return [TreeNode(n, l, r) for i, n in enumerate(num) for l in gen(num[:i]) for r in gen(num[i + 1:])] if num else [None]
        return bool(n) * gen([*range(1, 1 + n)])
```
- 思路同下

```python
# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x, l=None, r=None):
        self.val = x
        self.left = l
        self.right = r

class Solution:
    def generateTrees(self, n: int) -> List[TreeNode]:
        def gen(num):
            if not num: yield None
            for i, n in enumerate(num):
                for l in gen(num[:i]):
                    for r in gen(num[i + 1:]):
                        yield TreeNode(n, l, r)
        
        return bool(n) * [*gen([*range(1, 1 + n)])]
```
- 构建递归生成器 `gen`，输入是一系列升序的数字，返回这些数字可能构成的所有二叉树结构
- 首先，所有数字都有可能作为根，因此遍历 `num` 作为根
- 根据二叉搜索树的特性（左子树所有节点小于根，右子树大于），可知根的左子树由比根小的数字构成，递归 `num[:i]` 就是左子树所有的可能结构，同理可获得右子树所有可能的结构
- 左右递归结果的笛卡尔积 + `root`，即为整棵树所有可能的结构