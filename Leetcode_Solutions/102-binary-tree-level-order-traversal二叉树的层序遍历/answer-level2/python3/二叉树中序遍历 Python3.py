### 解题思路
用一个列表存储根节点和根节点的左右孩子和他们所在的层数
然后顺序遍历该列表，将当前节点的左右孩子及所在层数加入到当前列表的末端，直到当前列表遍历完毕
用Python字典把每一层分开，并用列表的形式返回

![QQ截图20200127151749.png](https://pic.leetcode-cn.com/9090b8df020c2f3fe5f1bf6aa11e5edcff956efa1853433fe0507b5da845f549-QQ%E6%88%AA%E5%9B%BE20200127151749.png)


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
        if not root:
            return []
        temp = [[root, 1]]
        i = 0
        while i<len(temp):
            if temp[i][0]:
                if temp[i][0].left: temp.append([temp[i][0].left, temp[i][1]+1])
                if temp[i][0].right: temp.append([temp[i][0].right, temp[i][1]+1])
            i += 1
        res_dict = {}
        for j in temp:
            res_dict.setdefault(j[1], []).append(j[0].val)
        res = []
        for k in sorted(res_dict):
            res.append(res_dict[k])
        return res

```