### 解题思路
可以通过层次遍历，看x,y是否在一个层级，再看他们是否同父节点（在遍历时记录）。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isCousins(self, root: TreeNode, x: int, y: int) -> bool:
        #可以通过层次遍历，看x,y是否在一个层级，再看他们是否同父节点。       
        from collections import deque
        queue=deque()
        queue.append(root)
        res=[]
        level=0
        lv1=0
        lv2=0
        lv0=[]
        while queue:
            res.append([])
            level_len=len(queue)
            for _ in range(level_len):
                curNode=queue.popleft()
                res[level].append(curNode.val)
                if curNode.left:
                    queue.append(curNode.left)
                    if curNode.left.val==x or curNode.left.val==y:lv0.append(curNode.val)#记录x/y的父节点
                if curNode.right:
                    queue.append(curNode.right)
                    if curNode.right.val==x or curNode.right.val==y:lv0.append(curNode.val)#记录x/y的父节点
            level+=1
        #print(res,'\n')
        for lv in range(len(res)):#判断是否同层
            if x in res[lv]:
                lv1=lv
            if y in res[lv]:
                lv2=lv
        #print(lv1,lv2)
        if lv1!=lv2:return False#不是同层节点直接返回False
        else:#是同层节点,判断是否同父节点
            return True if lv0[0]!=lv0[1] else False




```