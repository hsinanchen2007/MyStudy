其实就是一个家谱

执行用时 : 68 ms, 在Populating Next Right Pointers in Each Node的Python提交中击败了96.08% 的用户
内存消耗 : 14.1 MB, 在Populating Next Right Pointers in Each Node的Python提交中击败了5.35% 的用户
```vbscript
'''
next理解为弟弟
left理解为大儿子
right理解为二儿子 
要点：
    1.二叉树层序遍历
    2. 当前节点大儿子的弟弟是二儿子
    3. 当前节点如果有弟弟，二儿子的弟弟就是叔叔的大儿子
    4.遍历终止条件当前节点没有儿子 或者 当前节点为None（root=None情况）


'''
class Solution(object):
    def connect(self, root):
        def helper(root):
            if not root:
                return 
            if not root.left:
                return 
            root.left.next = root.right
            if root.next:
                root.right.next = root.next.left
            helper(root.left)
            helper(root.right)
        helper(root)
        return root
        
```
