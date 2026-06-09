### 解题思路
1. 建立一个列表，先把根节点和节点所在层次作为一个元素存入列表
2. 遍历列表，把当前节点的左孩子和右孩子和对应的层次放入列表，重复此过程直至列表遍历完毕
3. 把每个层次的加和存入默认值为0的字典
4. 从字典中选取value最大的key并返回

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
from collections import defaultdict

class Solution:
    def maxLevelSum(self, root: TreeNode) -> int:
        node_list = []
        if root:
            node_list.append([1, root])
        for i in node_list:
            if i[1].left:
                node_list.append([i[0]+1, i[1].left])
            if i[1].right:
                node_list.append([i[0]+1, i[1].right])
        res_dict = defaultdict(lambda: 0)
        for i in node_list:
            res_dict[i[0]] += i[1].val
        res = max(res_dict, key=lambda x: res_dict[x])
        return res

```