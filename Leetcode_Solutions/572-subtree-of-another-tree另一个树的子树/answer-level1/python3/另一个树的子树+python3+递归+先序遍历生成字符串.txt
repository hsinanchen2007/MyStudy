### 1. 递归
创建一个辅助函数判断两棵树是否相同。代码如下：
```
class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
        if not t:
            return True
        if not s:
            return False
        return self.isSame(s,t) or self.isSubtree(s.left,t) or self.isSubtree(s.right,t)
        
    def isSame(self,p,q):
        if not p and not q:
            return True
        if not p or not q:
            return False
        return p.val==q.val and self.isSame(p.left,q.left) and self.isSame(p.right,q.right)
```
### 2. 先序遍历
先序遍历两个树，生成两个字符串，判断一个字符串是不是另一个字符串的子串**(可以参考：[二叉树各种遍历算法](https://www.cnblogs.com/anzhengyu/p/11083568.html))**。代码如下：
```
class Solution:
    def isSubtree(self, s: TreeNode, t: TreeNode) -> bool:
        ss = self.inorder(s)
        st = self.inorder(t)
        print(st,ss)
        return st in ss
        
    def inorder(self,root):
        if not root:
            return '#'
        return '*'+str(root.val)+self.inorder(root.left)+self.inorder(root.right)
        # *是为了防止两个数个位数相同（比如：2，12）造成的误判，因此用一个符合标记数字开头
```
