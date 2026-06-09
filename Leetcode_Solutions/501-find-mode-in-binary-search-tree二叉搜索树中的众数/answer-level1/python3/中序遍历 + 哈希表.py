### 解题思路


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
        def inOrder(node):
            if not node: return []
            return inOrder(node.left) + [node.val] + inOrder(node.right)
        nums = inOrder(root)  # 中序遍历得到值列表
        dic = {}  # 记录每个值次数
        for i in nums:
            dic[i] = dic.get(i, 0) + 1
        new_dic = sorted(dic.items(),key=lambda x:(x[1],x[0]),reverse=True)  # 倒序排序
        out = [i for i, j in new_dic if j == new_dic[0][1]]  # 出现次数等于最大出现次数的值
        return out
```