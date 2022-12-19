一 算法思路
根据二叉搜索树的性质：
如果val小于当前结点的值，转向其左子树继续搜索；如果val大于当前结点的值，转向其右子树继续搜索；如果已找到，则返回当前结点。
如果搜索到最后仍未找到结点，则返回None。
二 算法实现
```
class Solution:
    def searchBST(self, root: TreeNode, val: int) -> TreeNode:
        p = root
        while p:
            if val < p.val:
                p = p.left
            elif val > p.val:
                p = p.right
            else:
                return p
        return None
```
三 复杂度分析
时间复杂度：O(log(N)),N为树中节点数。特殊情况树畸形时，时间复杂度为O(N)。
空间复杂度：O(1)。