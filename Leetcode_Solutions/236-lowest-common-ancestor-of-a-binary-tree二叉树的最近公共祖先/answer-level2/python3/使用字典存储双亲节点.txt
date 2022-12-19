由于每个节点只有唯一一个父节点，我们可以使用到字典的value-key的形式（节点-父节点）  
__字典中预置根节点的父节点为None。__  

字典建立完成后，二叉树就可以看成一个所有节点都将最终指向根节点的链表了。  

__于是在二叉树中寻找两个节点的最小公共节点就相当于，在一个链表中寻找他们相遇的节点__  

后面的思路可以参考力扣中这个题目的代码实现 [160.相交链表](https://leetcode-cn.com/problems/intersection-of-two-linked-lists/)  
```Python
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        dic = {root:None}
        def dfs(node):
            if node:
                if node.left: 
                    dic[node.left] = node
                if node.right: 
                    dic[node.right] = node
                dfs(node.left)
                dfs(node.right)
        dfs(root)
        l1, l2 = p, q
        while(l1!=l2):
            l1 = dic.get(l1, q)
            l2 = dic.get(l2, p)
        return l1 
```


