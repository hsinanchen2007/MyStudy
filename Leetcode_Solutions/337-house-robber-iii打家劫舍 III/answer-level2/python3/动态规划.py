### 解题思路
用列表存储不偷和偷的状态
[不偷,偷]
    不偷= max左树 + max右树
      偷 = 当前节点(n.val) + 左树不偷+右树不偷

   

### 代码

```python3
class Solution:
    def rob(self, root: TreeNode) -> int:
        def h(n):
            if not n:
                return [0,0]
            res = [0,0]
            l = h(n.left)
            r = h(n.right)
            res[0] = max(l)+max(r)
            res[1] = n.val + l[0] +r[0] 
            return res
        return max(h(root))
        
```