### 解题思路
![image.png](https://pic.leetcode-cn.com/8762f58239c80e749c859e5c9e69a7737e46a196bb403e31f6625500103ad8df-image.png)

3 -> return max((9),(20))+1

9 -> return max((null),max(null))+1
null -> return 0
所以9 -> return max(0,0)+1 -> 1

20 -> return max((15),(7))+1
15 -> return max((null),(null)) + 1 -> 1
7  -> return max((null),(null)) + 1 -> 1
所以20 -> return max(1,1)+1 -> 2

所以3 -> return max((9),(20))+1 -> max(1,2)+1 -> 3

![image.png](https://pic.leetcode-cn.com/bcf7057a17a97ecc5b9968785590dc613c500efd7d3bab58a640c2e9a0e88077-image.png)



### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def maxDepth(self, root: TreeNode) -> int:
        if not root:
            return 0
        
        return max(self.maxDepth(root.left),self.maxDepth(root.right)) + 1
```