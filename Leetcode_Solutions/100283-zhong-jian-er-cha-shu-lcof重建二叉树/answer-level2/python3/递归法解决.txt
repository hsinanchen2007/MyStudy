```
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        p1, p2, i1, i2 = 0, len(preorder)-1, 0, len(inorder)-1
        def construct(p1, p2, i1,i2):
            tmp = i1
            while tmp <= i2:
                if preorder[p1] == inorder[tmp]:
                    root = TreeNode(inorder[tmp])
                    root.left = construct(p1+1, p1+1+tmp-i1, i1, tmp-1)
                    root.right = construct(p1+1+tmp-i1, p2, tmp+1, i2)
                    return root
                else:
                    tmp += 1
            else:
                return None

        return construct(p1,p2,i1,i2)
```
