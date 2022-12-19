### 解题思路
1. 递归，分别计算取当前子节点和不取当前子节点的，取max，python运行的时候超时了
2. 优化递归，利用字典存储已经计算了的节点对应的最大值，节省了大量的计算
3. 利用动态规划，分为取当前子节点，不取当前子节点，分别求每个节点两个状态的最大值

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def rob(self, root: TreeNode) -> int:
        # if not root:
        #     return 0
        # sum = root.val
        # if root.left:
        #     sum += self.rob(root.left.left) + self.rob(root.left.right)
        # if root.right:
        #     sum += self.rob(root.right.left) + self.rob(root.right.right)
        # return max(sum, self.rob(root.left) + self.rob(root.right))

        # if not root:
        #     return 0
        # record = dict()
        # def rob2(root):
        #     if not root:
        #         return 0
            
        #     if root in record:
        #         return record[root]
            
        #     get_rob_left = rob2(root.left.left) + rob2(root.left.right) if root.left else 0
        #     get_rob_right = rob2(root.right.left) + rob2(root.right.right) if root.right else 0
        #     rob_num = get_rob_left + get_rob_right + root.val

        #     not_get_rob_left = rob2(root.left) if root.left else 0
        #     not_get_rob_right = rob2(root.right) if root.right else 0
        #     not_rob_num = not_get_rob_left + not_get_rob_right

        #     record[root] = max(rob_num, not_rob_num)
        #     return record[root]
        # return rob2(root)

        # record记录前子节点的最大值，0表示不盗窃当前的子节点，1表示盗窃当前的子节点
        def rob2(root):
            record = [0, 0]
            if not root:
                return record
            
            left  = rob2(root.left)
            right = rob2(root.right)

            # 不盗窃当前的子节点，所以取之前子节点的最大值
            record[0] = max(left[0], left[1]) + max(right[0], right[1])
            # 盗窃当前子节点，则最大值为子节点不盗窃的最大值和当前值之和
            record[1] = root.val + left[0] + right[0]
            return record
        record = rob2(root)
        return max(record[0], record[1])
```