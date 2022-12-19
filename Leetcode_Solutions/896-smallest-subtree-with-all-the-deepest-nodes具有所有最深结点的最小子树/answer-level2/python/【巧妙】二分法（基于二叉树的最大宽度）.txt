![3.png](https://pic.leetcode-cn.com/3257d96bd503c1a8a4ffa235cc3fdb69a68522bfc292517d31bfed939d9b4639-3.png)

# 基本思想：
1.首先根据**662题“二叉树的最大宽度”**，将节点在该层中的索引存入order
2.取出最深层的最左和左右元素的索引min_deep，max_deep
(注意：如果仅有一个最深层节点，则直接返回这个节点)
3.将l,r初值赋为0、最大层数的可能最多个数2^d-1，d为最大深度
4.【二分法】从根节点出发，递归寻找能够涵盖min_deep，max_deep的最小范围l,r对应的节点
（1）如果max_deep<=(l+r+1)/2-1:递归左节点
（2）如果min_deep>=(l+r+1)/2：递归右节点
（3）否则：返回当前节点（即再缩小范围则会不包括a或b）

```
class Solution:
    def subtreeWithAllDeepest(self, root: TreeNode) -> TreeNode:
        if not root:return None
        if not root.left and not root.right:return root
        order=[]
        #层次遍历（depth为深度，index为节点在节点所在层的索引）
        def main(depth,root,index):
            if not root:return 
            try:
                order[depth].append([index,root])
            except:
                order.append([[index,root]])
            main(depth+1,root.left,2*index)
            main(depth+1,root.right,2*index+1)
        main(0,root,0)
        min_deep,max_deep=order[-1][0][0],order[-1][-1][0]
        
        if min_deep==max_deep:return order[-1][0][1]
        #迭代：找到满足涵盖min_deep,max_deep的范围对应节点
        #l,r=0,2**(len(order)-1)-1
        def find(root,l,r):
            if max_deep<=(l+r+1)/2-1:return find(root.left,l,(l+r+1)/2-1)
            elif min_deep>=(l+r+1)/2:return find(root.right,(l+r+1)/2,r)
            return root
        return find(root,0,2**(len(order)-1)-1)
```
