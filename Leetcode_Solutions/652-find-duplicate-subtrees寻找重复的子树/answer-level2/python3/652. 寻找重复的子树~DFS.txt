### 解题思路
有一个直接的想法就是：我们进行递归的时候，将每个节点保存到一个列表中，如果递归过程中，有重复的节点出现过，那么这个节点就是相同的节点，但是很不幸这种直接保存节点的方式并没有奏效!(我猜想可能的原因就是每个节点的ID不相同，虽然两个数的结构相同，但是他们的ID并不相同，而python比较两个对象是否相等恰恰是比较两个对象的ID是否相同)
**但是如何去解决呢？？**
> 将树通过前序遍历换成字符串，我们去判断两个字符串是否相等即可，但是
如果俩个树结构不同， 但是遍历的字符串相同（如下图），那么还是不能解决，为了体现出不同的结构，我们将左右节点为空的时候设置为“#”（其他字符也行）

![image.png](https://pic.leetcode-cn.com/b643a1e360522c5fe406af29a05ce7fce1e820a83bd236c5b394504253679939-image.png)


### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution:
    def findDuplicateSubtrees(self, root: TreeNode) -> List[TreeNode]:
        from collections import defaultdict
        visited = defaultdict(int)
        res = []
        def dfs(root):
            if root is None: # 递归的时候返回的值
                return '#'
            series = str(root.val) 
            series += dfs(root.left) 
            series += dfs(root.right)
            
            visited[series] = visited.get(series, 0) + 1
            if visited[series] == 2:
                res.append(root)

            return series # 每个节点的返回值
            
        dfs(root)

        return res
```