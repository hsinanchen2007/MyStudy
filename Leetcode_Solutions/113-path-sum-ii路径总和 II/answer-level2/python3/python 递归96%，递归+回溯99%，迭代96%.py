```
#纯递归 96%
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        def help(node, path, pathSum, arr):
            if node.left == None and node.right == None and pathSum == sum:
                arr.append(path)
            if node.left != None:
                leftPath = path[:]
                leftPath.append(node.left.val)
                leftPathSum = pathSum + node.left.val
                help( node.left, leftPath, leftPathSum, arr)
            if node.right != None:
                rightPath = path[:]
                rightPath.append(node.right.val)
                rightPathSum = pathSum + node.right.val
                help( node.right ,rightPath, rightPathSum, arr)
        if root == None:
            return []
        arr = []
        help(root,[root.val],root.val,arr)
        return arr

# 递归+回溯 99%
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        self.tmp = []
        res = []
        def help(root, sum, res, tmp):
            if root == None:
                return
            tmp.append(root.val)
            if root.left == None and root.right == None and sum - root.val == 0:
                final = tmp[:]
                res.append(final)
            help(root.left, sum - root.val, res, tmp)
            help(root.right, sum - root.val, res, tmp)
            tmp.pop()
        help(root, sum, res, self.tmp)       
        return res

#迭代 91%
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        if root == None:
            return []
        nodeStack = [root]
        pathStack = [{"path":[root.val],"sum":root.val}]
        res = []
        while(nodeStack):
            curNode = nodeStack.pop()
            cur = pathStack.pop()
            curPath = cur["path"]
            curSum = cur["sum"]
            if curNode.left == None and curNode.right == None and curSum == sum:
                res.append(curPath)
            if curNode.left != None:
                nodeStack.append(curNode.left)
                leftPath = curPath[:]
                leftPath.append(curNode.left.val)
                pathStack.append({"path":leftPath,"sum":curSum + curNode.left.val})
            if curNode.right != None:
                nodeStack.append(curNode.right)
                rightPath = curPath[:]
                rightPath.append(curNode.right.val)
                pathStack.append({"path":rightPath,"sum":curSum + curNode.right.val})
        return res
```
