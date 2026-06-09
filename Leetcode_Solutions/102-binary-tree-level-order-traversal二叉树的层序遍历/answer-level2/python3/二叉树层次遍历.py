### 解题思路
这道题难度不大，比中序遍历的递归解法难一些，但并没有中序的迭代解法更难。解题的关键在于**分开记录**好相关的信息，比如正在遍历的第i层的节点，以及将要访问的第i+1层的节点，分开存储比较好。另外需要一个临时数组保存当前遍历的第i层节点的值，以及一个保存所有层节点值的数组。只要将这些用于保存信息的数据结构设置好，剩下的就好办了。每次第i层的节点遍历完毕后，将第i层的值加入最终结果数组中。然后判断是否还有第i+1层节点需要遍历，如果没有，则遍历完毕；如果有，则进行下一层遍历。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def levelOrder(self, root: TreeNode) -> List[List[int]]:
        if root == None:
            return []

        vals = []
        cur_level_vals = []
        cur_level_nodes = [root]
        next_level_nodes = []
        while True:
            while cur_level_nodes:
                node = cur_level_nodes.pop(0)   # 每次弹出最前面的元素
                if node.left:
                    next_level_nodes.append(node.left)
                if node.right:
                    next_level_nodes.append(node.right)
                cur_level_vals.append(node.val) # 遍历完的节点，保存其值
            vals.append(cur_level_vals)     # 保存刚刚访问完的一层节点的值
            cur_level_vals = []     # 将数组清空，准备保存下一层节点的值
            if next_level_nodes:    # 有下一层节点
                cur_level_nodes = next_level_nodes  
                next_level_nodes = []
            else:   # 没有下一层节点，跳出循环
                break
        return vals
        


```