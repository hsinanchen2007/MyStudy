```
'''
LeetCode 145. 二叉树的后序遍历
Given a binary tree, return the postorder traversal of its nodes' values.
Example:
Input: [1,null,2,3]
   1
    \
     2
    /
   3
Output: [3,2,1]
Follow up: Recursive solution is trivial, could you do it iteratively?

题目大意：
给定一个二叉树，返回它的 后序 遍历。
示例:
输入: [1,null,2,3]
   1
    \
     2
    /
   3
输出: [3,2,1]
进阶: 递归算法很简单，你可以通过迭代算法完成吗？

解题思路：
这道题属于Hard
后续遍历其实就是左右中，对于本题例子
root是1
先访问左，啥都没
再访问右，如下
     2
    /
   3
递归的，后序遍历左右中，此时中为2
先访问左，那就是3
再访问右，none
再访问中，那就是2
全部左右都访问完
再访问最前面的中，那就是root，为1
后序遍历结果，[3,2,1]

方法1：递归 去和94以及144对比，你看看自己应该可以理解
class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        def helper(root):
            if not root:
                return
            helper(root.left)
            helper(root.right)
            res.append(root.val)
        helper(root)
        return res
方法2：迭代 去和94以及144对比
这就跟先序一样,我们可以改变入栈的顺序,刚才先序是从右到左,我们这次从左到右,最后得到的结果取逆.
class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        if not root:
            return res
        stack = [root] # root先在栈中
        while stack:
            node = stack.pop() # 此时node是root，也即是中
            if node.left :
                stack.append(node.left) # 先压入左
            if node.right:
                stack.append(node.right) # 再压入右
            res.append(node.val) # 此时node其实是
        return res[::-1] # res是中右左，因为入栈是左右中，所以返回倒序
PS：后序遍历迭代，只能这样，因为你不可能不访问root就访问到左右子树，所以结果需要逆序，这也是为什么hard
就想链表一样，查找第5个点，你必须从head一个一个遍历到第五个节点，树只不过是多一个指针的树形链表而已
'''
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def postorderTraversal(self, root: TreeNode) -> List[int]:
        res = []
        if not root:
            return res
        stack = [root] # root先在栈中
        while stack:
            node = stack.pop() # 此时node是root，也即是中
            if node.left :
                stack.append(node.left) # 先压入左
            if node.right:
                stack.append(node.right) # 再压入右
            res.append(node.val) # 此时node其实是
        return res[::-1] # res是中右左，因为入栈是左右中，所以返回倒序
```
