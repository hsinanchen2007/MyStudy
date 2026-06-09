一 算法思路
递归
（1）如果t是空，直接返回""。
（2）令结果res=str(t.val)
（3）如果t.left存在，令res+="("，之后以t.left递归调用函数，在令res+=")"。如果在t.left存在的条件下，t.right也存在，以同样的方式将t.right作为实参进行处理。
（4）如果t.left不存在，若t.right存在，则先将结果前补"()"，再进行与（3）中相似处理。
（5）返回结果res。
二 算法
```
class Solution:
    def tree2str(self, t: TreeNode) -> str:
        if t is None:
            return ""
        res = str(t.val)
        if t.left:
            res += "("
            res += self.tree2str(t.left)
            res += ")"
            if t.right:
                res += "("
                res += self.tree2str(t.right)
                res += ")"
        else:
            if t.right:
                res += "()("
                res += self.tree2str(t.right)
                res += ")"
        return res
```
三 复杂度分析
时间复杂度：由于要以前序遍历方式访问树中每个节点，所以时间复杂度为O(N)，N为书中节点个数。
空间复杂度：O(h)，空间复杂度为递归最大深度，即树的高度h。
