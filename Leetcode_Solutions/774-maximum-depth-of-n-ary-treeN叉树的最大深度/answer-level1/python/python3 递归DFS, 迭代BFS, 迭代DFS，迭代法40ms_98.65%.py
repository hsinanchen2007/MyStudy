![微信截图_20200322013427.png](https://pic.leetcode-cn.com/3ba130d76fba54746a4582f5d91e63c0f0ffeaaa1ec06a7f2f518a54f146f08b-%E5%BE%AE%E4%BF%A1%E6%88%AA%E5%9B%BE_20200322013427.png)


法1，递归法，dfs
时间复杂度：我们访问每个节点一次，时间复杂度为 O(N) 。
空间复杂度：最坏情况下，整棵树是非平衡的，例如每个节点都只有一个孩子，递归会调用 N（树的高度）次，因此栈的空间开销是 O(N)。
但在最好情况下，树是完全平衡的，高度只有 log(N)，因此在这种情况下空间复杂度只有 O(log(N)) 。

```

class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if not root: return 0
        if root.children:
            depth_children=[self.maxDepth(node) for node in root.children]
        else:
            return 1
        return max(depth_children)+1   
```





法2，迭代法BFS
时间O(N),空间O(N)
```

class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if not root: return 0
        depth=1
        queue=[(root,depth)]
        while queue:
            root,depth=queue.pop(0)
            if root.children:
                for node in root.children: 
                    queue.append((node,depth+1))
        return depth
```


法3，迭代法dFS
时间O(N),空间O(N)

```
class Solution:
    def maxDepth(self, root: 'Node') -> int:
        if not root: return 0
        final_depth=1
        stack=[(root,final_depth)]
        while stack:
            root,depth=stack.pop()
            final_depth=max(final_depth,depth)
            if root.children:
                for node in root.children: 
                    stack.append((node,depth+1))
        return final_depth
```
