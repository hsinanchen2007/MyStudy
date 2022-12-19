### 解题思路
同[主站习题101](https://leetcode-cn.com/problems/symmetric-tree/) 

这一题关键是要想到：要比较 left.left 和 right.right  以及 left.right 和 right.left
题解区 liweiwei 大佬给了递归法 和层次遍历法。
另一个解答 [C++与Python两种解法实现：递归与迭代](https://leetcode-cn.com/problems/dui-cheng-de-er-cha-shu-lcof/solution/cyu-pythonliang-chong-jie-fa-shi-xian-di-gui-yu-di/) 也不错。



### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSymmetric(self, root: TreeNode) -> bool:
        def helper(left, right):
            if left == None and right == None:
                return True
            elif left == None or right == None:
                return False
            else:
                if left.val == right.val:
                    return helper(left.left, right.right) and helper(left.right, right.left)
                else:
                    return False

        if root == None:
            return True
        return helper(root.left, root.right)
```