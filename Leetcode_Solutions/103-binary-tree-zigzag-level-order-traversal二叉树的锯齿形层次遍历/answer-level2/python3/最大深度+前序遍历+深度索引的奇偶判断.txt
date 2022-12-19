### 解题思路
1. 题目目的：
- 从上到下，先从左到右，再从右到左，遍历二叉树
2. 解题思路：
- 求二叉树的最大深度
- 前序遍历+深度索引的奇偶判断

### 代码

```python3

class Solution:
    def zigzagLevelOrder(self, root: TreeNode) -> List[List[int]]:
        depth = self.get_depth(root)
        res = [[] for i in range(depth)]
        self.fill(root,res,0)
        return res

    def fill(self,root,res,depth_index):
        if not root:return
        #偶数：对首添加
        if (depth_index+1) % 2 == 0:
            res[depth_index].insert(0,root.val)
        #奇数：对尾添加
        else:
            res[depth_index].append(root.val)
        self.fill(root.left,res,depth_index+1)
        self.fill(root.right,res,depth_index+1)


    def get_depth(self,root):
        if not root:return 0
        return max(self.get_depth(root.left),self.get_depth(root.right))+1

```