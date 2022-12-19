思路和上题一样，后序的最后是根节点，还是去中序里去找该节点，再递归左右子树。


1.copy上题的官方题解，不过这里递归过程是从后序序列末尾依次向前选取，那么全局那个变量也要从最后开始依次递减，并且递归时要先递归右子树，再递归左子树，画下递归过程才好理解。。。我也想了半天

```
class Solution:
    def buildTree(self, inorder, postorder):
        def func(le=0,ri=len(postorder)):
            nonlocal x
            if ri-le<1:
                return None
            _val=postorder[x]
            x-=1
            root=TreeNode(_val)
            index=dic.get(_val)
            root.right=func(index+1,ri) #半闭半开
            #这俩顺序不能反
            root.left=func(le,index)    #半闭半开
            return root
        x=len(postorder)-1
        dic={value:key for key,value in enumerate(inorder)}
        return func()
```
2.自己写的，四个参数，分别指示两个序列当前考察的两段子序列范围。时间、空间使用情况和上面的写法是基本一致，但好理解一些。
注意这里递归子树时左右的先后就无所谓了，因为当前考察的两段中序、后序子序列范围已经明确给出了，不需要为了什么奇怪的全局变量改动代码布局，就是参数多了点看的头大。。
```
class Solution:
    def buildTree(self, inorder, postorder):
        def func(in_le,in_ri,po_le,po_ri):
            if in_ri-in_le<1:
                return None
            val=postorder[po_ri-1]
            root=TreeNode(val)
            index=dic.get(val)
            root.left=func(in_le,index,po_le,po_le+index-in_le)
            root.right=func(index+1,in_ri,po_le+index-in_le,po_ri-1)
            return root
        dic={value:key for key,value in enumerate(inorder)}
        return func(0,len(inorder),0,len(postorder))
```
