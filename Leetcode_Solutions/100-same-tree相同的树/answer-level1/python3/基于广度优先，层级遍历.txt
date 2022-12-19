### 解题思路
解答方法与题目102.level-order-traversal 思路、方法相同，基于广度优先搜索，逐层检查。唯一不同的是如果本node非空，但是缺少child时，应当加入None 占位；而本node 为 None 时，无需考虑。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:
        # deal with None
        if not p and not q:
            return True
        elif not p or not q:
            # single None
            return False
        # deal with normal
        nd_stack1 = [[p]]
        nd_stack2 = [[q]]
        
        while nd_stack1 != [[]] or nd_stack2 != [[]]:
            # 只要有一方不空，就应当继续判断

            cur_nds1 = nd_stack1.pop()
            cur_nds2 = nd_stack2.pop()
            cur_vals1,cur_vals2  = [],[]
            stack_temp1, stack_temp2 = [],[]
            for cur_nd1 in cur_nds1:
                if cur_nd1:
                    cur_vals1.append(cur_nd1.val)

                    # 为下一次做准备
                    if cur_nd1.left:
                        stack_temp1.append(cur_nd1.left)
                    else:
                        stack_temp1.append(None)
                    if cur_nd1.right:
                        stack_temp1.append(cur_nd1.right)
                    else:
                        stack_temp1.append(None)
                else:
                    cur_vals1.append(None)
                    # 本节点为 None, 孩子是否还需要占位？暂时认为不用压
            
            for cur_nd2 in cur_nds2:
                if cur_nd2:
                    cur_vals2.append(cur_nd2.val)

                    # 为下一次做准备
                    if cur_nd2.left:
                        stack_temp2.append(cur_nd2.left)
                    else:
                        stack_temp2.append(None)
                    if cur_nd2.right:
                        stack_temp2.append(cur_nd2.right)
                    else:
                        stack_temp2.append(None)

                else:
                    cur_vals2.append(None)
            
            if cur_vals1 != cur_vals2:
                # break while
                return False

            # 将下一层结构放入，等待审核
            nd_stack1.append(stack_temp1)
            nd_stack2.append(stack_temp2)
        # end while
        return True
```