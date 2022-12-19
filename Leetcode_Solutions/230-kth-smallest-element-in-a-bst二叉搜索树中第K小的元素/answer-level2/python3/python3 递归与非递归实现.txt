根二叉搜索树的特效: 任何一个节点大于其左子树(若存在)的所有节点值，小于其右子树(若存在)的所有节点值, 可以知道对其进行中序遍历可以得到一个顺序(升序)的数列nums,则nums[k-1]就是我们要求的第k小元素.

那么中序遍历该如何实现呢?

+ 递归实现中序遍历，并保存遍历过程中所有节点的值
```
class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        vals = []
        def inOrder(childroot):
            if not childroot:
                return
            inOrder(childroot.left)
            vals.append(childroot.val)
            inOrder(childroot.right)
        inOrder(root)
        return vals[k-1]
```

其缺点也很明显，需要占用辅助空间来保存遍历值. 我们能不能实现不保存遍历值，当遍历到第k个值的时候直接返回结果呢?

+ 递归实现中序遍历, 不保存遍历序列
```
class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        self.cur = 0
        self.val = 0
        def inorder_search(childroot):
            #if not childroot:
            if not childroot or self.cur > k:
                return 
            inorder_search(childroot.left)
            self.cur += 1
            if self.cur == k:
                self.val = childroot.val
                return 
            inorder_search(childroot.right)
        inorder_search(root)
        return self.val
```

+ 非递归遍历

左节点入栈，当某节点没有右节点时，pop栈顶元素，如果该栈顶元素存在右节点，则将右节点入栈，同时入栈其左节点(如果存在的话)
```
class Solution:
    def kthSmallest(self, root: TreeNode, k: int) -> int:
        stack = []
        cur = root
        while cur:
            stack.append(cur)
            cur = cur.left
        ind = 0
        while stack:
            top = stack.pop(-1)
            ind += 1
            if k == ind:
                return top.val
            if top.right:
                cur = top.right
                while cur:
                    stack.append(cur)
                    cur = cur.left
```