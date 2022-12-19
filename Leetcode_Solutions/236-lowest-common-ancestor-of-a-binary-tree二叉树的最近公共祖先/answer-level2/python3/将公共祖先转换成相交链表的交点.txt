```
class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        temp = p
        dic = self.bfs(root)
        # 将链表q拼在q的末尾
        # 这样将相交链表转换成环形链表
        while(dic.get(temp)):
            temp=dic.get(temp)
        dic[temp] = q  

        fast=slow=p
        # 快慢指针法，将公共祖先转换成相交链表的交点，也即环形链表的入口
        while(dic.get(fast)):
            fast = dic.get(dic.get(fast))
            slow = dic.get(slow)
            if(fast is slow): break
        while(fast!=p):
            p=dic.get(p)
            fast = dic.get(fast)
        return fast

    def bfs(self,root:TreeNode ) -> dict :
        # 层次遍历所有节点，将所有节点的与其父节点以字典形式存下来
        p = root
        queue = []
        if p: 
            dic = {p:None}
            queue.append(p)
        while(queue):
            p = queue.pop(0)
            if p.left: 
                dic[p.left]=p
                queue.append(p.left)
            if p.right: 
                dic[p.right]=p
                queue.append(p.right)
        return dic
```