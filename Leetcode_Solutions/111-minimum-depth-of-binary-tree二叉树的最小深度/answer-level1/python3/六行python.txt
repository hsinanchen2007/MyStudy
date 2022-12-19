    def minDepth(self, root: TreeNode) -> int:
        def back(r,i):
            if r:
                if r.left and r.right:
                    return min(back(r.left,i+1),back(r.right,i+1))
                else:
                    return max(back(r.left, i + 1), back(r.right, i + 1))
            else:return i
        return back(root,0)
# 思路：需要对每一个节点进行搜索
# 1. 判断r是否是空节点，如果不是空节点，
#       如果这个r有左子树同时又有右子树，则最小的深度加一，然后对左子树和右子树再循环，并且返回两个的最小值
#       如果只有一个子树，则这个节点肯定不算数，此时返回最大的值
# 2.如果r是空节点，则返回当前的深度