一 算法思路
特殊情况：树为空，返回0。
树不为空，层次遍历二叉树。
构造双端队列，并将根节点入队列。逐个弹出队列中元素并记录当前元素的编号，当弹出的元素左右子树都存在时，将其左右子树入队列。
若其左子树为空，则返回2倍元素编号减1。若左子树存在，右子树不存在，则返回2倍元素编号。
二 算法实现
```
class Solution:
    def countNodes(self, root: TreeNode) -> int:
        de = collections.deque()
        s = 0
        if root is not None:
            de.append(root)
        while de:
            p = de.popleft()
            s += 1
            if p.left:
                de.append(p.left)
            else:
                return (s << 1) - 1
            if p.right:
                de.append(p.right)
            else:
                return s << 1
        return 0
```
三、复杂度分析
时间复杂度：O(N)，N为树中节点个数。
空间复杂度：O(M)，M为树的最大宽度。
