### 解题思路
将每个节点当作根节点进行判断
用到了函数嵌套函数
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def pathSum(self, root: TreeNode, sum: int) -> int:
        # 将每个节点看作使根节点去找

        self.res =0

        def check(root, sum):
            if not root :return 
            if root.val == sum:
                self.res +=1
                print(root.val)
            sum -= root.val
            # print(sum)
            check(root.left, sum)
            check(root.right, sum)
            return 


        def countnum(root, sum):
            if not root: return
            # print(root.val)
            countnum(root.left, sum)
            countnum(root.right, sum)
            check(root, sum)

            return

        countnum(root, sum)
        # print(root.left.left.val)
        return self.res
```