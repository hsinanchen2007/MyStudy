## 思路:

思路一：暴力法

两个`dfs`即可

思路二：前缀和 + 回溯

## 代码:

思路一：

```python
class Solution:
    def pathSum(self, root: TreeNode, _sum: int) -> int:
        res = 0
        
        def dfs1(root, _sum):
            nonlocal res
            if not root:return 
            if _sum - root.val == 0: res += 1
            _sum -= root.val
            dfs1(root.left, _sum)
            dfs1(root.right, _sum)
        
        def dfs2(root):
            if not root:return 
            dfs1(root, _sum)
            dfs2(root.left)
            dfs2(root.right)
        
        dfs2(root)
        return res
```

思路二：

```python
class Solution:
    def pathSum(self, root: TreeNode, _sum: int) -> int:
        from collections import defaultdict
        prefix = defaultdict(int)
        # 前缀和的个数
        prefix[0] = 1
        res = 0

        def dfs(root, cur):
            nonlocal res 
            if not root:
                return 
            cur += root.val
            target = cur - _sum
            res += prefix[target]
            prefix[cur] += 1
            dfs(root.left, cur)
            dfs(root.right, cur)
            # 回溯
            prefix[cur] -= 1

        dfs(root, 0)
        return res
```

