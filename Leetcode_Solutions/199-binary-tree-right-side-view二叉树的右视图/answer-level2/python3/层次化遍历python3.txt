class Solution:
    """
    先对二叉树进行层次化遍历（也称广度优选遍历），将出每一层的节点都拿出来放进一个列表中，然后取出
    这样列表的最后一个节点的值，最中返回这个存放最后一个值的列表
    """
    def rightSideView(self, root: TreeNode) -> List[int]:
        rightVal = []
        tempList = []
        if root is None:
            return rightVal
        else:
            cNodeList = [root]
            nNodeList = []
        while True:
            if cNodeList:
                node = cNodeList.pop(0)
                tempList.append(node.val)
                if node.left and node.right:
                    nNodeList.append(node.left)
                    nNodeList.append(node.right)
                elif node.left:
                    nNodeList.append(node.left)
                elif node.right:
                    nNodeList.append(node.right)
                else:
                    pass
            else:
                rightVal.append(tempList[:].pop(-1))
                tempList = []
                if not nNodeList:
                    break
                else:
                    cNodeList = nNodeList[:]
                    nNodeList = []
        return rightVal