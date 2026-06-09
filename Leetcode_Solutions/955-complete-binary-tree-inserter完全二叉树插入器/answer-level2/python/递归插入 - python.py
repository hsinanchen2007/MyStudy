### 解题思路

需要维护树的节点数、高度。

树的高度 h = math.floor(math.log(节点数,2)+1)

每次插入的时候：
1. 计算当前的叶子节点数（`leaf_cnt = int(cnt - 2 ** (h-1)+1)`），当前最后一层叶子节点最多有多少（`full_leaf_cnt = int(2 ** (h-1))`）
  1. 如果当前叶子节点数是 0 到 最大数//2，或者是叶子节点满了递归到左子树
  2. 如果不是递归到右子树

递归的退出条件是：子树的节点数 == 1 直接插入当前节点的左孩子，节点数 == 2 插入为右孩子。

### 代码

```python
# Definition for a binary tree node.
# class TreeNode:
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class CBTInserter:

    def __init__(self, root: TreeNode):
        self.root = root
        self.cnt = 0
        self.get_cnt(root)
        self.h = math.floor(math.log(self.cnt,2)+1)

    def get_cnt(self, root):
        if root:
            self.cnt += 1
            self.get_cnt(root.left)
            self.get_cnt(root.right)
        

    def insert(self, v: int) -> int:
        if self.cnt == 0:
            self.root = TreeNode(v)
        else:
            return self.do_insert(v, self.cnt, self.h, self.root)

    def do_insert(self, v, cnt, h, r):
        if cnt == 1:
            r.left = TreeNode(v)
            self.cnt += 1
            self.h = math.floor(math.log(self.cnt,2)+1)
            return r.val
        elif cnt == 2:
            r.right = TreeNode(v)
            self.cnt += 1
            self.h = math.floor(math.log(self.cnt,2)+1)
            return r.val
        else:
            leaf_cnt = int(cnt - 2 ** (h-1)+1) # 当前的叶子节点数
            full_leaf_cnt = int(2 ** (h-1))    # 最后一层叶子节点最多有多少
            if leaf_cnt == full_leaf_cnt:
                return self.do_insert(v, 2**(h-1)-1, h-1, r.left)
            elif leaf_cnt < full_leaf_cnt>>1:
                return self.do_insert(v, 2**(h-2)-1+leaf_cnt, h-1, r.left)
            else:
                return self.do_insert(v, 2**(h-2)-1+leaf_cnt-(full_leaf_cnt>>1), h-1, r.right)

    def get_root(self) -> TreeNode:
        return self.root


# Your CBTInserter object will be instantiated and called as such:
# obj = CBTInserter(root)
# param_1 = obj.insert(v)
# param_2 = obj.get_root()
```


欢迎来我的博客： [https://codeplot.top/](https://codeplot.top/)
我的博客刷题分类：[https://codeplot.top/categories/%E5%88%B7%E9%A2%98/](https://codeplot.top/categories/%E5%88%B7%E9%A2%98/)