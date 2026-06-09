DFS 栈stack前序遍历：
```
class Solution(object):
    def invertTree(self, root):
        stack=[]
        cur=root
        while stack or cur:
            while cur:
                cur.left,cur.right=cur.right,cur.left
                stack.append(cur)
                cur=cur.left
            cur=stack.pop()
            cur=cur.right
        return root
```
中序遍历时要把第一层循环的cur=cur.right改成cur=cur.left。
```
class Solution(object):
    def invertTree(self, root):
        stack=[]
        cur=root
        while stack or cur:
            while cur:                
                stack.append(cur)
                cur=cur.left
            cur=stack.pop()
            cur.left,cur.right=cur.right,cur.left
            cur=cur.left
        return root
```
