### 解题思路
这一题很重要。其实这里不用写 helper 函数，注意到 helper 函数的输入和输出和原函数输入和输出是一样的，并且两者所需要解决的子问题也是一样的，直接对原函数递归即可。 

#### 但下一题[113. 路径总和 II]() 和 [面试题 26](https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/) 就需要用辅助函数

对于树递归，我一直没搞懂到底要不要返回，之前忘了返回，[面试题26. 树的子结构-直接输出 None， 而不是 boolean 值 True False](https://leetcode-cn.com/problems/shu-de-zi-jie-gou-lcof/)

 有些地方是不能少递归的。

### 注意到，递归一定是减小问题规模，还要注意，子问题是如何构成主问题的解的。
#### 子问题所代表的的含义，子问题的返回值，子问题如何组合成为主问题的解
这里值得反复思考。


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def hasPathSum(self, root: TreeNode, sum: int) -> bool:
        def helper(root, res):
            if not root.left and not root.right and root.val == res:
                return True
            elif not root.left and not root.right and root.val != res:
                return False  ## 这里是不是 返回 False, 还是 不用 return ?? 要想清楚
            else:
                r1, r2 = False, False
                if root.left:
                    r1 = helper(root.left, res-root.val)
                if root.right:
                    r2 = helper(root.right, res-root.val)
                return r1 or r2
        if root == None:
            return False
        return helper(root, sum)
```