一 算法思路
1 递归
（1）递归边界处理：空树直接返回[]。
（2）对于非空的情况，首先递归调用函数本身顺序处理当前节点的各个子节点，并将访问到的各个节点值添加到结果列表中，最后再访问当前节点。之后返回结果列表。
2 栈（非递归）
正难则反
首先访问根节点，再将其子节点从左到右入栈，这样首先出栈的是它的最后一个子节点，因此得到的结果与要求是相反的，所以最后将列表反转输出即可。
二 算法实现
```
"""
# Definition for a Node.
class Node(object):
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution(object):
    def postorder(self, root):
        """
        :type root: Node
        :rtype: List[int]
        """
        
        if root is None:
            return []
        res = []
        for child in root.children:
            res.extend(self.postorder(child))
        res.append(root.val)
        return res
        
        # # method 2
        # if root is None:
        #     return []
        # st = [root]
        # res = []
        # while st:
        #     p = st.pop()
        #     res.append(p.val)
        #     for child in p.children:
        #         st.append(child)
        # return res[::-1]
```
三 复杂度分析：
1 时间复杂度：O(N)，N为树中节点数。
2 空间复杂度
递归方法：O(H), H为树的高度。
非递归方法：O(N)。