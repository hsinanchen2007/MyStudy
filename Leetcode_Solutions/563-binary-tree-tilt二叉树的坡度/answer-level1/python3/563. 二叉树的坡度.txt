### 解题思路
自下往上递归，请看下图，结合代码很好理解
>1.我们只要知道递归终止条件是什么，一般都是遍历到叶子节点应该返回的是什么（可以直接return或者return 一个bool类型或者是一个整数类型，具体看题目要求，这里我们返回0就行）
>2.递归的的过程中碰到每个***节点要返回什么
>3.递归过程中我们需要记录什么（代码中的全局变量res）
![image.png](https://pic.leetcode-cn.com/4bd8c281d22af3f366157327183c332bf546d6b2f74e3a7ba0802249405565d0-image.png)


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findTilt(self, root: TreeNode) -> int:
        res = 0
        def dfs(root):
            nonlocal res
            if root is None:
                return 0
            
            left_sum = dfs(root.left) 
            right_sum = dfs(root.right)

            res += abs(left_sum - right_sum)
            
            return left_sum + right_sum + root.val

        dfs(root)
        return res


            
```