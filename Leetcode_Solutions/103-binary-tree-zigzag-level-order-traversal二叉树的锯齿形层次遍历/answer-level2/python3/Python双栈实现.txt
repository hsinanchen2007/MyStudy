本道例题可以通过双栈的方式来实现，一个栈记录一层，算法中的关键点是反向记录的栈要先入右边的节点。

最终结果是：执行用时 :56 ms, 在所有Python3提交中击败了80.42%的用户
                      内存消耗 :13.3 MB, 在所有Python3提交中击败了61.40%的用户

``` python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        if not root:
            return []

        d1 = [] # 从左向右存储的栈
        d2 = [] # 从右向左存储的栈 d2和d1完成锯齿状存储的任务
        res = [] # 保存输出结果
        tmp = [] # 临时存储结果
        d1.append(root) 
        while(True):
            while d1:
                curr = d1[-1]
                d1.pop()
                tmp.append(curr.val)
                if curr.left: # 左边的节点先入栈
                    d2.append(curr.left)
                if curr.right:
                    d2.append(curr.right)
            if tmp:
                res.append(tmp)
                tmp = []
            else:
                break
            
            while d2:
                curr = d2[-1]
                d2.pop()
                tmp.append(curr.val)
                if curr.right: # 这里是右边的节点先入栈
                    d1.append(curr.right)
                if curr.left:
                    d1.append(curr.left)
            if tmp:
                res.append(tmp)
                tmp = []
            else:
                break
        
        return res
```