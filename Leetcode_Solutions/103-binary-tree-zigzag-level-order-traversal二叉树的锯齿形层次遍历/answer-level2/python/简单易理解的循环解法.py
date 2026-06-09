### 解题思路
此处撰写解题思路
设置一个初始的j=0 
设置一个列表b 将根节点加入列表中
当j为偶数的时候 从前到后顺序读取列表的值 加入结果列表res中，声明新的列表a，之后从后向前遍历列表，先将右节点加入a中，再将左节点加入a中，之后将a赋值给b
当j为奇数的时候 从前到后顺序读取列表的值 加入结果列表res中，声明新的列表a，之后从后向前遍历列表，先将左节点加入a中，再将右节点加入a中，之后将a赋值给b
### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def zigzagLevelOrder(self, root):
        """
        :type root: TreeNode
        :rtype: List[List[int]]
        """
        if root == None:
            return []
        node_stack = []
        node_stack.append(root)
        j = 0
        res = []
        while node_stack:
            if j%2 == 0:
                n = len(node_stack)
                new_stack = []
                res_tmp = []
                for i in range(0,n):
                    res_tmp.append(node_stack[i].val)
                res.append(res_tmp)
                #print 'aaa'
                #print res_tmp
                for i in range(n-1,-1,-1):
                    if node_stack[i].right:
                        new_stack.append(node_stack[i].right)
                    if node_stack[i].left:
                        new_stack.append(node_stack[i].left)
                node_stack = []
                node_stack = new_stack
                #print node_stack
            elif j%2 == 1:
                n = len(node_stack)
                new_stack = []
                res_tmp = []
                for i in range(0,n):
                    res_tmp.append(node_stack[i].val)
                res.append(res_tmp)
                #print 'bbb'
                #print res_tmp
                for i in range(n-1,-1,-1):
                    if node_stack[i].left:
                        new_stack.append(node_stack[i].left)
                    if node_stack[i].right:
                        new_stack.append(node_stack[i].right)
                node_stack = []
                node_stack = new_stack
            j += 1
            #res.append(res_tmp)
        return res
                    
                






```