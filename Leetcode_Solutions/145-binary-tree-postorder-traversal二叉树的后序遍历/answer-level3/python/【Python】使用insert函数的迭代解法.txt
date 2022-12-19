### 解题思路
后序遍历即，左中右，拿[1,null,2,3,4]来看，其后序遍历为[3,4,2,1],我们可以看到其实对于后序遍历，最后遍历的都是树的右边部分的一条线，那么我们可以一直先遍历树的右边，并同时利用insert函数把值向前加入遍历结果中，此时可以满足中右的排列，在右边遍历完的同时，再开始判断每个节点左边是否有子树，有的话就往前插入，就可以变成左中右了，第一次看到这个思路的时候觉得不太好理解，但是想清楚了的话就会觉得还是很妙的~

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        stack = []
        ans = []
        while stack or root:
            if root:
                stack.append(root)
                ans.insert(0, root.val)
                root = root.right
            else:
                root = stack.pop()
                root = root.left
        return ans
```


