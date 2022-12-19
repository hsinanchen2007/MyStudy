### 解题思路
简单的dfs,层序遍历二叉树，用哈希表k-v分别对应层数和层中元素。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxLevelSum(self, root: TreeNode) -> int:
        walked=[[root,1]]
        my_dic={}
        res=0
        while walked:
            head,cengshu = walked.pop(0)
            if cengshu in my_dic:
                my_dic[cengshu].append(head.val)
            else:
                my_dic[cengshu] = [head.val]
            
            if head.left:
                walked.append([head.left,cengshu+1])
            if head.right:
                walked.append([head.right,cengshu+1])
        max_val=float('-inf')
        for k,v in my_dic.items():
            if sum(v)>max_val:
                max_val = sum(v)
                res=k
        return res
                
```