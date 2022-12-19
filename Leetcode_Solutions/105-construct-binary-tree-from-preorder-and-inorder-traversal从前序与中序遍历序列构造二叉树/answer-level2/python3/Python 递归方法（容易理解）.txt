思路：前序序列为【根，左子树，右子树】，中序序列为【左子树，根，右子树】。
          我们可以不断从前序序列把根拿出来，划分中序序列。
Tips: 前序序列拿出根后，就分为左右子树。其中左右子树的组成还是【根，左子树，右子树】，并且前序和中序的左右子树是对应的。

```python3 []
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        def goujian(p1, p2):
            if not p2:
                return None
            else:
                t = p1.pop(0)
                T1 = TreeNode(t)
                i = p2.index(t)
                T2 = goujian(p1,p2[:i])
                T3 = goujian(p1,p2[i+1:])
                T1.left = T2
                T1.right = T3
                return T1
            
        T = goujian(preorder, inorder)
        return T
```