![image.png](https://pic.leetcode-cn.com/28cf6ef63564deb345b2489dbcc2b2c976944678f5cfd62ca5baa0c4a6f65b0a-image.png)


初看难到爆炸，原理想了半天，最后做出来的代码，和其他大佬本质上也没啥区别，就是只要递归出的传来的数列不为空，就把前序数列的头给砍了放进树里。
代码前面做一个中序数列的坐标哈希，减少坐标查找次数，前序数列传坐标，相当于是在砍头。

```
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        d = {j:i for i, j in enumerate(inorder)}
        k = 0
        def f(i, j):
            if i < j:
                nonlocal k
                t = TreeNode(preorder[k])
                k += 1
                t.left = f(i, d[t.val])
                t.right = f(d[t.val] + 1, j)
                return t
        return f(0, len(inorder))
```

整个子中序数列一起传更容易理解一些，这个就是纯砍头了，但因为要反复查坐标，所以效率也低一些，最好大概87%左右吧

```
class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        def f(ino):
            if ino:
                t = TreeNode(preorder.pop(0))
                i = ino.index(t.val)
                t.left = f(ino[: i])
                t.right = f(ino[i + 1:])
                return t
        return f(inorder)
```
