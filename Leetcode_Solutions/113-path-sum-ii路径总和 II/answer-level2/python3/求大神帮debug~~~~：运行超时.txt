
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        def PathSum(root, sum) :
            ri=[]
            if not root:return []

            if (not root.left and not root.right) and (sum==root.val) :
                return [[root.val]]

            if PathSum(root.left,sum-root.val):
                for i in PathSum(root.left,sum-root.val):
                    ri.append([root.val]+i)
            if PathSum(root.right,sum-root.val):
                for i in PathSum(root.right,sum-root.val):
                    ri.append([root.val]+i)
            return ri
        
        return PathSum(root, sum)