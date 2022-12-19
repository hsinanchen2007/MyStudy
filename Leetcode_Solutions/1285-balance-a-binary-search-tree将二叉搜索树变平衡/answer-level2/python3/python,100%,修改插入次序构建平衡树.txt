**思路：**
二叉搜索树的构建本质上就是二叉搜索树的插入操作，只不过由于节点数值插入的次序不同，最后形成的二叉搜索形态也会不一样。所以我们考虑通过改变插入数值的次序来使得最后的二叉搜索树是一棵平衡树。
**步骤**
1.利用二叉搜索树中序遍历得到有序数组
2.取有序数组s中点位置mid的数值s[mid]插入，构建一棵新的二叉搜索树root
3.取s[0:mid]和s[mid+1:]分别对新的二叉搜索树root重复2的操作，即可得到一颗平衡二叉树。
**代码**
```
class Solution:
    def order(self,root,s):
        if root==None:
            return
        self.order(root.left,s)
        s.append(root.val)
        self.order(root.right,s)
    def insert(self,root,val):
        if root==None:
            return TreeNode(val)
        if val<root.val:
            root.left=self.insert(root.left,val)
        if val>root.val:
            root.right=self.insert(root.right,val)
        return root
    def create(self,s,root):
        if s==None:
            return root
        if len(s)==0:
            return root
        mid=int(len(s)/2)
        root=self.insert(root,s[mid])
        root=self.create(s[0:mid],root)
        root=self.create(s[mid+1:],root)
        return root
    def balanceBST(self, root: TreeNode) -> TreeNode:
        s=[]
        self.order(root,s)
        head=None
        head=self.create(s,head)
        return head

```
