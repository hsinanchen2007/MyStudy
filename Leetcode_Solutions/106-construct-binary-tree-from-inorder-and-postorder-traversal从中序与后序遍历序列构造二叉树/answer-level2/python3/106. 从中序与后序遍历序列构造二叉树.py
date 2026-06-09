> 11.26 python

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        # postorder: A-左-B|C-右-ZV
        # inorder:   D-左-EVF-右--G
        # V表示根节点
        # inorder中的DEFG非常好确定, 分别是D=instart, E = V-1, F = V+1, G=size-1=inend
        # postorde中的A=pstart, B = pstart + L_length - 1, C = pstart+L_length+1, Z=pend-1
        # 所以还需要一个计算量L_length = V - instart
        in_pos = {ele:idx for idx, ele in enumerate(inorder)}
        size = len(inorder)

        def dfs(inorder, postorder, pstart, pend, instart, inend):
            # print(pstart, pend, instart, inend)
            if pstart > pend or instart > inend:
                return None

            r = postorder[pend]
            in_root_pos = in_pos[r]
            L_length = in_root_pos - instart

            root = TreeNode(r)
            root.left = dfs(inorder,postorder,pstart,pstart+L_length-1,instart,in_root_pos-1)
            root.right = dfs(inorder,postorder,pstart+L_length+1,pend-1,in_root_pos+1,inend)

            return root

        return dfs(inorder, postorder, 0, size-1, 0, size-1)
```