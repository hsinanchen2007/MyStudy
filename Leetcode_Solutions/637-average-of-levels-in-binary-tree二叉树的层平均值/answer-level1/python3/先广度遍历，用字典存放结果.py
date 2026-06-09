### 解题思路
此处撰写解题思路

### 代码

```python3
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None
class Solution:
    def averageOfLevels(self, root: TreeNode) -> List[float]:
        #节点和深度
        st = [(root,1)]
        #  深度为key，同层节点val组成的数组为字典的value
        ans = {}
        while st:
            node,level = st.pop(0)
            if str(level) in ans:
                ans[str(level)].append(node.val)
            else:
                ans[str(level)] = [node.val]

            if node.left:
                st.append((node.left,level+1))
            if node.right:
                st.append((node.right,level+1))
        tmp = []
        for i in range(1,len(ans)+1):
            sum = 0
            for value in ans[str(i)]:
                sum += value
            tmp.append(sum / len(ans[str(i)]))
        return tmp
```