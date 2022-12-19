### 解题思路
看作对数组求众数：遍历二叉搜索树，然后用字典存储.时间效率不太高
时间复杂度：o(nlogn)
空间复杂度：o(n)
### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findMode(self, root: TreeNode) -> List[int]:
        if not root:
            return None
        stack = [root]  # 使用栈
        dicts = {}
        while stack:  # 当栈不为空时
            node = stack.pop()  # 弹出栈顶的节点
            if node:  # 若节点存在:
                if node.val not in dicts:
                    dicts[node.val] = 1
                else:
                    dicts[node.val] += 1
                # 入栈应是先右子节点, 再左子节点
                stack.extend([node.right, node.left])
        lists = sorted(dicts.items(),key=lambda x:x[1],reverse=True)
        result = []
        for i in range(len(lists)):
            if lists[i][1] == lists[0][1]:
                result.append(lists[i][0])
        return result


```