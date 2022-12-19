### 解题思路
新手入门，只能用这种比较笨拙的方法：直接建立数组，哪一层有节点，就将之放入数组对应的层数内，没有什么取巧的地方。。。甚至因为函数构造，最后一层会出现一个空数组，也只能用如下方法检测排除。

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
        def strip(root,depth,lists):
            if root:
                lists[depth].append(root.val)
                depth += 1
                if len(lists)<=depth:
                    lists.append([])
                if root.left:
                    strip(root.left,depth,lists)
                if root.right:
                    strip(root.right,depth,lists)
                if lists[depth] == []:
                    lists.pop(depth)
            return lists
        if not root: return []
        lists = [[]]
        return strip(root,0,lists)
                
```