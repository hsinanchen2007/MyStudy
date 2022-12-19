
思路：最大差值只可能出现在左子树，右子树，或者头节点与左（右）子树某个节点的差值
所以递归函数返回三个值：子树的最大值，子树的最小值，子树的最大差值
整合左右子树信息时再考虑头节点即可
```
class Solution:
    def maxAncestorDiff(self, root: TreeNode) -> int:
        if root is None:
            return 0


        def process(node):
            if node.left == None and node.right == None:
                return node.val, node.val, 0
            left, right = (-1,-1,0), (-1,-1,0) # 初始为无效数字
            if node.left != None:
                left = process(node.left)
            if node.right != None:
                right = process(node.right)
            # 下面开始整合两棵树的信息
            if node.left != None and node.right!= None:
                return min(left[0], right[0], node.val), max(left[1], right[1], node.val), max(left[2], right[2], abs(node.val-left[0]),abs(node.val-left[1]), abs(node.val-right[0]), abs(node.val-right[1]))
            else:
                if node.left == None:
                    return min(right[0], node.val), max(right[1], node.val), max(abs(right[0]-node.val), abs(right[1]-node.val), right[2])
                else:
                    return min(left[0], node.val), max(left[1], node.val), max(abs(left[0]-node.val), abs(left[1]-node.val), left[2])
        return process(root)[2]
```
