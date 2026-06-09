### 解题思路

1. 为每个节点添加编号，root是pos，左孩子是2pos，右孩子是2pos+1，存到一个字典当中
2. 遍历过程中要检查是不是对p,q都编过号了，如果都编过了那我们也可以跳出遍历的循环了
3. 取出p和q的编号，当两者不相等时，编号较大者不断除2，直至二者相等，此时的值就是LCA的编号
4. 从字典中取出对应编号的key即可

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def lowestCommonAncestor(self, root: TreeNode, p: TreeNode, q: TreeNode) -> TreeNode:
        if not root:
            return None
        
        dicts = {}
        stack = [(1,root)]
        has_p,has_q = False,False
        while stack:
            lv,root = stack.pop()
            dicts[root] = lv

            if root == p:
                has_p = True
            elif root == q:
                has_q = True
            if has_p and has_q:
                break

            if root.right:
                stack.append((lv*2+1,root.right))
            if root.left:
                stack.append((lv*2,root.left))

            
        
        pos_p,pos_q = dicts[p],dicts[q]
        while pos_p!=pos_q:
            if pos_p>pos_q:
                pos_p//=2
            else:
                pos_q//=2
        for k,v in dicts.items():
            if v == pos_p:
                return k
```