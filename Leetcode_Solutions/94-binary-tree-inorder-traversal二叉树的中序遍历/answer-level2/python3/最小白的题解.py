```
'''
LeetCode 94. 二叉树的中序遍历
Given a binary tree, return the inorder traversal of its nodes' values.
Example:
Input: [1,null,2,3]
   1
    \
     2
    /
   3

Output: [1,3,2]
Follow up: Recursive solution is trivial, could you do it iteratively?

题目大意：
给定一个二叉树，返回它的中序 遍历。
示例:
输入: [1,null,2,3]
   1
    \
     2
    /
   3
输出: [1,3,2]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

预备知识：
middle难度的题目，先给你介绍一下二叉树，树本身是一种数据结构，再次强调全部数据结构都是一种思想，如并查集
树，顾名思义，是有根节点，不断向下分裂的树形结构，可以有多叉树，比如
1
2 3 4 5
其中1是根节点，值val=1，有四个next指针，分别指向2 3 4 5这四个叶子节点。
树和链表一样，每一个节点都包括val+next指针，树只不过多些next指针
特别的，二叉树是最常用的一种数据结构，对于每一个节点，只有两个next指针
也就是说，二叉树的根包括一个val值，一个指向左孩子的left指针，一个指向右孩子的right指针，比如
1
2 3
其中1是根节点root，root.val = 1, root.left = 2, root.right = 3

解题思路：
前面讲了，二叉树结构，对于当前节点，都有左孩子和右孩子
中序遍历是什么，是遍历树的一种形式，中序遍历就是左中右的方式进行遍历，举个例子
  1
    \
     2
    /
   3
先定位root，root是1，我们中序遍历，先访问root的左孩子，注意这里是递归下去的，最最先访问的是左子树的左子树的。。。左孩子
先访问左，我们发现root没左子树，那我们左就全部访问完了（其实都为None，啥也没访问到）
然后访问中，那就是1了
然后访问右，右子树是
     2
    /
   3
我们还要递归的左中右访问，2是root，也就是中
先访问左，那就是3
在访问中，那就是自身2
最后访问右，啥也没有
至此，全部访问完毕，中序遍历顺序是 1，3，2

方法1：递归，宏观过程思考
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        def helper(root):
            if not root:
                return
            helper(root.left) # 先左
            res.append(root.val) # 中
            helper(root.right) # 最后右
        helper(root)
        return res
方法2：迭代，使用栈
class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        stack = []
        # 用p当做指针，先把左子树全部压入
        p = root
        while p or stack: # p是不断遍历左右孩子的，保证左右孩子一直存在，栈不为空，因为要返回全部res
            while p:
                stack.append(p) # 中序遍历，左中右，先将左全部压入stack
                p = p.left
            p = stack.pop() # 把当前最左侧的元素弹出来
            res.append(p.val) # 值添加到输出list里
            p = p.right # 再看右节点需要不需要迭代
        return res

PS：前面讲过
如果从下标从1开始存储，则编号为i的结点的主要关系为：
双亲：下取整 （i/2）
左孩子：2i
右孩子：2i+1
如果从下标从0开始存储，则编号为i的结点的主要关系为：
双亲：下取整 （(i-1)/2）
左孩子：2i+1
右孩子：2i+2

对于这道题例子的[1,null,2,3]，你去算可能不符合上面，是因为最后一个节点比较特殊
第一个null是根结点1的左节点，2是根结点1的右节点，3是2的左节点，到此结束了
因为，你的2的自节点都是null，3无处安放了
'''
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def inorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        stack = []
        # 用p当做指针，先把左子树全部压入
        p = root
        while p or stack: # p是不断遍历左右孩子的，保证左右孩子一直存在，栈不为空，因为要返回全部res
            while p:
                stack.append(p) # 中序遍历，左中右，先将左全部压入stack
                p = p.left
            p = stack.pop() # 把当前最左侧的元素弹出来
            res.append(p.val) # 值添加到输出list里
            p = p.right # 再看右节点需要不需要迭代
        return res
```
