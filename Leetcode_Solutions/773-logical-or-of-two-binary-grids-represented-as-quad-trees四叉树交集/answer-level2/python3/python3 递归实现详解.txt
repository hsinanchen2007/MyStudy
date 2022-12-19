整体思路：
递归
1 考虑递归出口（base case）
根据题目要求，或运算，两个叶子节点中只要有一个的值为Ture，返回结果就应该为Ture。
所以递归出口应该是：两个输入的节点，当有一个节点为叶子结点并且其值为Ture时，返回该节点，若不是返回另一个节点。
两个节点都需要进行判断。
2 考虑递归条件
返回的递归条件应该看问题需要输出什么，本题目要输出的是节点，所以返回的条件也应该是一个节点。
只要输入的两个节点没有满足递归出口的条件，就需要继续递归。
具体代码如下：

class Solution:
    def intersect(self, quadTree1: 'Node', quadTree2: 'Node') -> 'Node':
        if quadTree1.isLeaf:
            if quadTree1.val:
                return quadTree1
            else:
                return quadTree2
        if quadTree2.isLeaf:
            if quadTree2.val:
                return quadTree2
            else:
                return quadTree1
        topleft = self.intersect(quadTree1.topLeft,quadTree2.topLeft)
        topright =  self.intersect(quadTree1.topRight,quadTree2.topRight)
        bottomLeft =  self.intersect(quadTree1.bottomLeft,quadTree2.bottomLeft)
        bottomRight =  self.intersect(quadTree1.bottomRight,quadTree2.bottomRight)
        if topleft.isLeaf and topright.isLeaf and bottomLeft.isLeaf and bottomRight.isLeaf and topleft.val and topright.val and bottomLeft.val and bottomRight.val:
            return Node(True,True,None,None,None,None)
        else:
            return Node(False,False,topleft,topright,bottomLeft,bottomRight)

时间复杂度：O（N*N），空间复杂度：O（N*N）