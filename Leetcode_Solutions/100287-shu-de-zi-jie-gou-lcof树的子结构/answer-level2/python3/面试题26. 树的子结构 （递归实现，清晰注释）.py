### 代码

```python3
class Solution:
    def isSubStructure(self, main: TreeNode, sub: TreeNode) -> bool:
        """
        递归
        先找子树的根，找到后，再判断其左右子结构。
        """
        if main is None or sub is None:
            return False

        res = False

        # 如果根相同，那么就判断 main 是否有 sub 相同的子结构
        if main.val == sub.val:
            res = self.isSubStructureWhenTheyHaveSameRoot(main, sub)

        # 根不同则在 main 的左右子树中继续找
        if not res:
            res = self.isSubStructure(main.left, sub)
        if not res:
            res = self.isSubStructure(main.right, sub)
        return res

    def isSubStructureWhenTheyHaveSameRoot(self, main: TreeNode, sub: TreeNode) -> bool:
        # sub 遍历结束，那么意味 main 含有 sub 的完整结构
        if sub is None:
            return True
        # main 遍历结束而 sub 没有，那么意味着 main 不具备 sub 完整的结构
        if main is None:
            return False

        if main.val != sub.val:
            return False

        # 继续在两个子树中判断
        return self.isSubStructureWhenTheyHaveSameRoot(main.left, sub.left) and \
               self.isSubStructureWhenTheyHaveSameRoot(main.right, sub.right)
```