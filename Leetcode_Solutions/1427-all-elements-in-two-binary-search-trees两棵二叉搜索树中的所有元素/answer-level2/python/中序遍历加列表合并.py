### 解题思路
先通过前序遍历构造成树转中序遍历，然后在把得到的两个列表合并排序一下就行

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def getAllElements(self, root1: TreeNode, root2: TreeNode) -> List[int]:
        # 在这先用中序遍历
        res1 = mid_tree(root1, [])
        res2 = mid_tree(root2, [])
        res = []
        while res1 and res2:
            if res1[0]<res2[0]:
                res.append(res1[0])
                del res1[0]
            else:
                res.append(res2[0])
                del res2[0]
        if res1:
        # 在这就是讲list1剩下的直接接到最后的结果中去
            res.extend(res1)
        if res2:
            res.extend(res2)
        return res

def mid_tree(root,res):
    if root == None:
        return None
    mid_tree(root.left, res)
    res.append(root.val)
    mid_tree(root.right,res)
    return res

```