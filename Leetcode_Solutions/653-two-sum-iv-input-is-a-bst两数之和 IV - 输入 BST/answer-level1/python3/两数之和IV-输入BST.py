### 解题思路
第167题是对于一个升序数组找到两个数之和等于目标值；
本题的输入是BST，可以利用中序遍历将BST中的节点数值存储成升序数组；再利用第167题的方法检查是否能找到两个数等于目标；

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    """
    第167题中，对于一个升序排序的数组，找到2个数之和等于target；
    因此本题将BST中的节点按中序遍历将节点依次存储到一个列表中，再用第167题中的方法找到两数和等于target；
    """
    def findTarget(self, root: TreeNode, k: int) -> bool:
        """
        中序遍历可以用递归方法或迭代方法；本题采用迭代方法；
        """
        node_stack = []
        num_list = []
        cur = root
        while cur or node_stack:
            while cur:
                node_stack.append(cur)
                cur = cur.left
            if node_stack:
                cur = node_stack.pop()
                num_list.append(cur.val)
                cur = cur.right
        
        if len(num_list) < 2:
            return False
        index1, index2 = 0, len(num_list)-1
        while index1 < index2:
            if num_list[index1] + num_list[index2] == k:
                return True
            elif num_list[index1] + num_list[index2] < k:
                index1 += 1
            else:
                index2 -= 1
        return False
        
```