###  解题思路
这道题让我更深刻的认识了层次遍历用队列的形式进行求解，并且可以知道下一层结点的个数：
count是用来计数队列中队头结点的子节点的个数的，count2是用来计数count的，之后将count清零，count2不清零的原因是因为：count2是代表下一次要循环的次数，也就是下一层的节点数，算法的根本思想就是统计出：对当前层中，我一共在队列中添加了多少个子节点，记录下这个结点的个数（count2），代表着我下一次出栈的次数。下一次循环中，循环的次数是针对刚才计算的count2的个数来的，每次循环都要出栈一次，也就是出栈的次数就是刚才统计出count2的次数。
```
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if root is None:
            return []
        ls = [];rs=[]
        queue=[root]
        count =0 ;count2=1
        while queue:
            while count2>0:
                node = queue.pop(0)
                ls.append(node.val)
                if node.left:
                    queue.append(node.left)
                    count+=1
                if node.right:
                    queue.append(node.right)
                    count+=1
                count2 -=1
            count2=count
            count=0
            rs.append(ls)
            ls=[]
        return rs
```