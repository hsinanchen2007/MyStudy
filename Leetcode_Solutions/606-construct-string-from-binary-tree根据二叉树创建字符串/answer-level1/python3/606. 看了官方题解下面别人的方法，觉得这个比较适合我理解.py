### 解题思路
要分四种情况来考虑：
1. 没有root的时候，返回空，这里初始化了一个self.ans。
2. 如果没有左右的时候，保留当前节点的值即可，不需要进行任何其他操作。
3. 如果只有右，情况比较复杂一点，因为需要把左表示出来，因此在处理的时候，需要在右边多加一一组'()'
4. 如果只有左，就不需要考虑右的情况，把左用'()'包围起来即可。

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def __init__(self):
        self.ans = ''

    def tree2str(self, t: TreeNode) -> str:

        def count(root):
            if not root:
                return self.ans
            elif not root.left and not root.right:
                return str(root.val) + ''
            elif root.right:
                return str(root.val) + '(' + count(root.left) + ')' + '(' + count(root.right) + ')'
            else:
                return str(root.val) + '(' + count(root.left) + ')'
        
        self.ans += count(t)
        return self.ans
```