刚看到题目，觉得特别简单，分别对树做个遍历，存在两个list里，比较两者是否相等。
于是选择了中序遍历，然而跑出来之后，发现忽略了值相等的情况，比如[1,1]和[1，null, 1] ，无论哪种遍历都会出[1,1]
进而我想到了在遍历到空的节点时放入一个None数值到list里，用来区分树的形状的区别，值得注意的用中序遍历仍然分不出我举例的这种情况。
因为相同的部分在中间，这时候改成先序或者后序即可。

```
class Solution:
    def isSameTree(self, p: TreeNode, q: TreeNode) -> bool:       
        list1=[]
        list2=[]
        def travel(node,list0):
            if node is None:
                list0.append(None)
                return
            travel(node.left,list0)
                                        #空的位置本来是中序的
            travel(node.right,list0)
            list0.append(node.val)      #后序遍历
        travel(p,list1)
        travel(q,list2)
        return list1==list2
```
