树的题一般都可以用递归求解，这道也不例外
算法：
用变量res记录走过的路径
ans用来保存结果
1.从根节点开始，将节点的路径记录下来
2.判断是否到达了叶节点，如果到了并同时正好和是目标值，保存结果
3.如果没有则继续递归

时间复杂度：因为走遍了所有节点，时间复杂度为O(N)


# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> List[List[int]]:
        # write code here
        target = sum 
        #递归的办法
        if root == None:
            return []
        self.ans = []
        res = []
        def FindPath1(root,res,resnumber):
            res.append(root.val)
            resnumber -= root.val
            if root.left == None and root.right == None and resnumber == 0:
                self.ans.append(res)
            if root.left:
                FindPath1(root.left,res.copy(),resnumber)
            if root.right:
                FindPath1(root.right,res.copy(),resnumber)
            return 
        FindPath1(root,res,target)
        return self.ans
```
