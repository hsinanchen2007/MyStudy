递归思想
测试用时40ms，内存14mb

class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        if p==None and q==None:
        # 先判断p，q是不是都是空树；
            return True
        elif p and q:
        # 再判断p或q是不是其一是空树；
            if p.val==q.val:
            # 若pq都非空，判断root是否相同
                if self.isSameTree(p.left,q.left) and self.isSameTree(p.right,q.right):
                # 递归调用isSameTree
                    return True
        else:
            return False

这样大概可以最大程度上减少判断递归前做的判断步骤