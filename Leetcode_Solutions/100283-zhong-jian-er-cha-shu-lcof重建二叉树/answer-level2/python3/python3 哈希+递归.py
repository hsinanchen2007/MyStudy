### 解题思路
使用一个 dict 记录每个元素在 inorder 中的位置，构建递归函数：
1.若当前序列为空，返回 None
2.确定当前需要构建的子树的树根节点 root 的位置x，去 dict 中查找当前 pre[0]所在的位置，再减去相应的差值（sub)
3.递归，此时x 将 pre和 ino 序列一分为二，分别对应，左子树需要减去的差值为sub,右子树需要减去的差值为sub+x+1
4.返回 root

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        dic={}
        for i in range(len(inorder)):
            dic[inorder[i]]=i
        def build(pre,ino,sub):
            if not pre:
                return None
            x=dic[pre[0]]-sub
            root=TreeNode(pre[0])
            root.left=build(pre[1:x+1],ino[:x],sub)
            root.right=build(pre[x+1:],ino[x+1:],x+1+sub)
            return root
        return build(preorder,inorder,0)
```