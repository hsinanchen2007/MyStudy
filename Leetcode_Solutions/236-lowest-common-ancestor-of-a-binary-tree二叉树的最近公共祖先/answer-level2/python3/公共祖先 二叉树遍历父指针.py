### 解题思路
一开始先写了用两个栈的递归写法, 记录每个节点的path, 然后都找到后再倒序寻找公共结点

```
def search(path, root, target):
            if not root: return False
            path.append(root)
            if root.val==target.val: 
                return True
            if search(path, root.left, target): return True
            elif search(path, root.right, target): return True
            else: 
                path.pop()
                return False   
        s1, s2 = [], []
        search(s1, root, p)
        search(s2, root, q) # 两次遍历树
        l1, l2 = len(s1), len(s2)
        l = min(l1, l2)
        if l1<l2: 
            for _ in range(l2-l1):
                if s1[-1].val == s2.pop().val: return s1[-1]
        elif l1>l2:
            for _ in range(l1-l2):
                if s2[-1].val == s1.pop().val: return s2[-1]    
        while l:
            n1, n2 = s1.pop(), s2.pop()
            if n1.val==n2.val: return n1
            l -= 1
```
然后在题解里看到个更简洁的递归遍历, 只需要遍历一次

```
def solve(node):
            if not node: return None
            if node==p or node==q:
                return node # 找到这个结点就返回它
            left = solve(node.left)
            right = solve(node.right)
            
            if not left: # 如果某边孩子为空, 则两个target只能来自另一边
                return right
            elif not right: 
                return left
            else: # 如果两边都非空, 说明一边一个, 则当前结点即为公共祖先
                return node
        return solve(root)
```

非递归写法! 父指针技巧, 新建一个parent字典存储每个节点的父节点, 学习!
```

class Solution:
    def lowestCommonAncestor(self, root: 'TreeNode', p: 'TreeNode', q: 'TreeNode') -> 'TreeNode':
        parent = {root: None}
        stack = [root]
        while p not in parent or q not in parent:
            node = stack.pop()
            if node.left: 
                stack.append(node.left)
                parent[node.left] = node
            if node.right: 
                stack.append(node.right)
                parent[node.right] = node
        
        path = set()
        while p:
            path.add(p)
            p = parent[p]
        while q not in path:
            q = parent[q]
        return q



        


        # def solve(node):
        #     if not node: return None
        #     if node==p or node==q:
        #         return node
        #     left = solve(node.left)
        #     right = solve(node.right)
            
        #     if not left:
        #         return right
        #     elif not right: 
        #         return left
        #     else:
        #         return node
        # return solve(root) 

        # def search(path, root, target):
        #     if not root: return False
        #     path.append(root)
        #     if root.val==target.val: 
        #         return True
        #     if search(path, root.left, target): return True
        #     elif search(path, root.right, target): return True
        #     else: 
        #         path.pop()
        #         return False   
        # s1, s2 = [], []
        # search(s1, root, p)
        # search(s2, root, q)
        # l1, l2 = len(s1), len(s2)
        # l = min(l1, l2)
        # if l1<l2: 
        #     for _ in range(l2-l1):
        #         if s1[-1].val == s2.pop().val: return s1[-1]
        # elif l1>l2:
        #     for _ in range(l1-l2):
        #         if s2[-1].val == s1.pop().val: return s2[-1]    
        # while l:
        #     n1, n2 = s1.pop(), s2.pop()
        #     if n1.val==n2.val: return n1
        #     l -= 1
        

        

```