（该方法借鉴了其他语言的答案）
使用递归求解时，发现python的好多答案都是基于中序遍历，借助list记录数组或dict记录频数。这里提供的方法不需要记录原数组，使用非局部变量记录前一个节点值、最大次数、当前节点值的次数和最终结果。注意：
- 若当前节点和前一个节点相等，则次数加1，否则为1；
- 若次数等于最大次数，结果列表添加当前节点值；若大于，删除结果列表中的所有节点，改为当前节点，更新最大次数。
```
class Solution:
    def findMode(self, root: TreeNode) -> List[int]:
        if not root:return []
        self.res=[]
        self.maxtimes=0
        self.pre=-float('inf')
        self.cur=1
        def inorder(root):
            if not root:return 0
            inorder(root.left)
            self.cur=self.cur+1 if root.val==self.pre else 1
            if self.cur==self.maxtimes:
                self.res.append(root.val)
            elif self.cur>self.maxtimes:
                self.res=[root.val]
                self.maxtimes=self.cur
            self.pre=root.val
            inorder(root.right)
        inorder(root)
        return self.res


```
