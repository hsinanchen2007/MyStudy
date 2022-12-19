### 解题思路
对输入对树结构做中序遍历，按顺序将遍历对节点放入数组，最后遍历数组做好指针即可。
更快的方法就是在遍历的时候直接做好指针(我懒得写, 而且不是很直观)。
### 代码

```python
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""
class Solution(object):
    def treeToDoublyList(self, root):
        """
        :type root: Node
        :rtype: Node
        """
        if not root:
            return None
        result_list = self.getChild(root)

        length = len(result_list)

        for i in range(length - 1):
            result_list[i].right = result_list[i + 1]
            result_list[i + 1].left = result_list[i]

        result_list[0].left = result_list[length - 1]
        result_list[length - 1].right = result_list[0]

        return result_list[0]

    def getChild(self, root):
        temp_list = []
        if root.left:
            temp_list.extend(self.getChild(root.left))

        temp_list.append(root)

        if root.right:
            temp_list.extend(self.getChild(root.right))

        return temp_list

```