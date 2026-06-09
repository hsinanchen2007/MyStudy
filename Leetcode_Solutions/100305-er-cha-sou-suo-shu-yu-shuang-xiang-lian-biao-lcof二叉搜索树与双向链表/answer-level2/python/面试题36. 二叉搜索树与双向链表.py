### 解题思路 ###
一个错误题解，欢迎下方评论
1.剑指 offer 书中思路 python 版
2.代码在哪里出现了问题
3.能否给出在此基础上的修改



    """
    # Definition for a Node.
    class Node(object):
        def __init__(self, val, left=None, right=None):
            self.val = val
            self.left = left
            self.right = right
    """
    class Solution(object):
        # def __init__(self):
        #     self.pLast = None

        def treeToDoublyList(self, root):
            """
            :type root: Node
            :rtype: Node
            """
            # phead = root
            # while phead.left:
            #     phead = phead.left

            pLast = None
            # 开始转换结点
            self.ConvertNode(root, pLast)
            
            # pLast 指向双向链表的尾结点，我们需要重新返回头结点
            pHead = pLast
            while pHead != None and pHead.left != None:
                pHead = pHead.left

            return phead

        def ConvertNode(self, pNode, pLast):
            # 叶结点直接返回
            if pNode == None:
                return

            pCurrent = pNode
            # 递归左子树
            if pCurrent.left != None:
                self.ConvertNode(pCurrent.left, pLast);
            
            # 左指针
            pCurrent.left = pLast
            # 右指针
            if pLast != None:
                pLast.right = pCurrent
            # 更新双向链表尾结点
            pLast = pCurrent

            # 递归右子树
            if pCurrent.right != None:
                self.ConvertNode(pCurrent.right, pLast)