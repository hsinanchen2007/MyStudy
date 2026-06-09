![image.png](https://pic.leetcode-cn.com/72dcb2e0438c21dfbdd2b2f0ab5e1a6a98e8923510482c5b01bb47bca0929bb5-image.png)

后续遍历序列从前往后就是左右根，从后往前就是根右左，所以每次取后序遍历的最后一个元素做子树的根，然后再递归右左子树就行，哈希是为了方便查找中序数列的坐标。

```
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        d={j:i for i,j in enumerate(inorder)}
        def f(i,j):
            if i<j:
                t=TreeNode(postorder.pop())
                t.right=f(d[t.val]+1,j)
                t.left=f(i,d[t.val])
                return t
        return f(0,len(inorder))
```
把后序数列的斩尾操作坐标化能更快一些

![image.png](https://pic.leetcode-cn.com/091025dcfd870ab67caa70e12dd5b2fb4056e8828bfed0b40f6612cc2489ead8-image.png)


```
class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        d={j:i for i,j in enumerate(inorder)}
        k=len(postorder)-1
        def f(i,j):
            if i<j:
                nonlocal k
                t=TreeNode(postorder[k])
                k-=1
                t.right=f(d[t.val]+1,j)
                t.left=f(i,d[t.val])
                return t
        return f(0,len(inorder))
```
