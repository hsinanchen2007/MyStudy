### 思路

**递归**

```
根据性质：
1. 后序遍历：左右根
2. 二叉搜索树：左子树任意节点的值 < 根节点的值，右子树任意节点的值 > 根节点的值

划分左右子树，分别判断子树是否满足二叉搜索树性质。

其他看代码注释。
```

**时间复杂度:** O(n^2)，n 为节点个数。
**空间复杂度:** O(n)，n 为节点个数。

##### Python3代码

```python
from typing import List

class Solution:
    def verifyPostorder(self, postorder: List[int]) -> bool:
        def recur(i, j):
            # 根节点小于等于1个
            if i >= j:
                return True
            l = i
            # 左子树
            while postorder[l] < postorder[j]:
                l += 1
            # 找到第一个大于根节点的节点，记为 m
            m = l
            # 右子树
            while postorder[l] > postorder[j]:
                l += 1
            # postorder[j]是根
            return l == j and recur(i, m - 1) and recur(m, j - 1)
        
        return recur(0, len(postorder) - 1)
```

### GitHub链接

[Python](https://github.com/Wonz5130/LeetCode-Solutions/blob/master/solutions/Interview-33-er-cha-sou-suo-shu-de-hou-xu-bian-li-xu-lie-lcof/33.py)