
## 错误解法

我一开始的解法是错误的，原因在于子结构应该是连续的。

比如：

```
例如:
给定的树 A:

     *3*
    / \
   4   5
  / \
 *1*   2
给定的树 B：

   3
  /
 1
```

这样是不包含的。

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSubStructure(self, A: TreeNode, B: TreeNode) -> bool:
        if not B:
            return True
        if not A:
            return False
        if A.val == B.val:
            return self.isSubStructure(A.left, B.left) and self.isSubStructure(A.right, B.right)
        return self.isSubStructure(A.left, B) or self.isSubStructure(A.right, B)
```

## 正确解法

因此我的想法变成了；

对于每一个A中的节点a，我们都判断其a是否是以a为根节点的B的结构。


比如题目给的例子：

```
树A：
    3
    / \
   4   5
  / \
 1   2
树 B：

   4 
  /
 1
```
- 我们首先判断3是否是以3为根节点的B。 明显不是，3和B的根节点数字根本就不等。我们返回False
- 我们继续判断4是否是以3为根节点的B。 我们判断4和B的根节点相等了，我们继续判断 以 4 为根节点的树是否有和B完全相等的结构。
- 如果有，我们返回True

我们定一个一个函数helper 来判断A（必须从根节点开始）是否包含B。

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSubStructure(self, A: TreeNode, B: TreeNode) -> bool:
        def helper(A, B):
            if not B:
                return True
            if not A:
                return False
            if A.val == B.val:
                return helper(A.left, B.left) and helper(A.right, B.right)
            return False
        if not A or not B:
            return False
        if helper(A, B):
            return True
        return self.isSubStructure(A.left, B) or self.isSubStructure(A.right, B)
```


欢迎关注我的公众号《脑洞前端》获取更多更新鲜的LeetCode题解

![](https://pic.leetcode-cn.com/89ef69abbf02a2957838499a96ce3fbb26830aae52e3ab90392e328c2670cddc-file_1581478989502)