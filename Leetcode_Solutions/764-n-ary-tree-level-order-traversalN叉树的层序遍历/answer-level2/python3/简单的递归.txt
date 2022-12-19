##成绩（2019-06-20）
执行用时 : 116 ms , 在所有 Python3 提交中击败了98.73%的用户

内存消耗 : 17.5 MB, 在所有 Python3 提交中击败了87.50%的用户

## 思路

就是很简单的递归，因为不是计算机专业的所以也想不出来迭代或者其他更巧妙的方法

唯一需要多加考虑的就是元素顺序的问题，这里我就用了一个前序遍历，先添加当前节点的值再按顺序对子节点进行相同操作。

因为事先并不知道树的深度所有才有了那个`try` `except`语句，至于`except`中用直接用append是因为上一层必然是存在的，所以我们添加下一层直接`append`就好。而这里并不需要担心顺序问题，因为我们的`append`和函数一样是优先访问左下节点然后再到右下节点的。

```
"""
# Definition for a Node.
class Node:
    def __init__(self, val, children):
        self.val = val
        self.children = children
"""
class Solution:
    def levelOrder(self, root: 'Node') -> List[List[int]]:
        ans = []
        def layer(root, ans, n_layer=0):
            if root:
                try:
                    ans[n_layer].append(root.val)
                except IndexError:
                    ans.append([root.val])
                for i in root.children:
                    layer(i, ans, n_layer+1)
        layer(root, ans)
        return ans
```

