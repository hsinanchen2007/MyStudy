验证是否可以形成一棵二叉树：
1.首先判断各结点之间是否会形成闭环，如果是直接返回False
2.构建一棵二叉树，从root（0）出发，是否可以穷尽所有结点（题目要求必须是“1棵”二叉树）
```
class Tree:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def validateBinaryTreeNodes(self, n: int, leftChild: List[int], rightChild: List[int]) -> bool:
        
        nodes_num = len(leftChild)
        tmp = [0]
        # 1.判断有没有形成环
        for l, r in zip(leftChild, rightChild):
            if l==-1 and r==-1: continue
            if l!=-1:
                if l in tmp:return False
                tmp.append(l)
            if r!=-1:
                if r in tmp:return False
                tmp.append(r)
        # 初始化各个树结点
        nodes = [Tree(i) for i in range(nodes_num)]
        
        # 2.构建二叉树
        for i, (l, r) in enumerate(zip(leftChild, rightChild)):
            if l!=-1:
                nodes[i].left = nodes[l]
            if r!=-1:
                nodes[i].right = nodes[r]
        self.num = 0
        # 借中序遍历访问root可达的所有结点 
        def inOrder(root):
            if not root:
                return 
            inOrder(root.left)
            self.num += 1
            inOrder(root.right)
            
        inOrder(nodes[0])
        # 如果从根结点出发不能穷尽所有结点，说明形成不止一棵二叉树
        if self.num != nodes_num:
            return False
        return True
```
