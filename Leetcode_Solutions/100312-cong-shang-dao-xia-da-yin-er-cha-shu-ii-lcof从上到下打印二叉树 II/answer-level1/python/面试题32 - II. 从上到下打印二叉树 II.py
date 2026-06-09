### 解题思路
**1.迭代 BFS**

### 代码

```python
# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Solution(object):
    def levelOrder(self, root):
        if not root:return []
        q = [(1,root)]
        ans = []
        temp = []
        l = 1
        while q:
            level,root = q.pop(0)
            if root:
                if level == l:
                    temp += [root.val]
                else:
                    l += 1
                    ans.append(temp)
                    temp = []
                    temp += [root.val]
                q.append((level+1,root.left))
                q.append((level+1,root.right))
        ans.append(temp)
        return ans

```
### 解题思路
**2.哈希表 递归**

```python

class Solution(object):
    def levelOrder(self, root):
        #哈希表用于储存每一层的结点
        dic = {}
        def bfs(root,level):
            if root:
                if level not in dic:
                    dic[level] = [root.val]
                else:
                    dic[level].append(root.val)
                bfs(root.left,level+1)
                bfs(root.right,level+1)
        bfs(root,1)
        #按照键值(层次)进行排序
        dic = sorted(dic.items(),key = lambda x:x[0])
        ans = []
        for c in dic:
            ans.append(c[1])
        return ans

```
