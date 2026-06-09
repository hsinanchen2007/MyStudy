```
"""
# Definition for a Node.
class Node:
    def __init__(self, val, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right
"""
这个答案虽然运行很慢，但是花了我一个小时的功夫，我的思路是将整个树前序遍历然后将每个叶子节点的右子节点指向有序数比他大一个的那个节点，然后整个树的right都满足了指向比他大的条件。后来发现根如果有右子节点，然后右子节点又有左子节点之后，那么这个根的右节点就错了，但是如果早就把右节点改过来，前序遍历便无法执行，所以我换成了后序遍历，后序遍历的好处就是你可以改变节点的左右子树，但是最后每个节点仍然会访问一遍，不会丢掉结点。
最后右节点会把整个树串联起来，最后在将单向链表换成双向链表即可。
class Solution:
    def treeToDoublyList(self, root: 'Node') -> 'Node':
        if root==None:return None
        def tree(head) :
            print(head.val)
            if head.left!=None:
                if head.left.right == None : head.left.right=head
                else:
                    p = head.left.right
                    while p.right != None:
                        p = p.right
                    p.right = head
            if head.right!=None and head.right.left!=None:
                p=head.right.left
                while p.left!=None:
                    p=p.left
                head.right=p
        def tree2(head,visited) :
            if head == None:return
            tree2 (head.left,visited+[head])
            if head.right in visited:return 
            tree2 (head.right,visited+[head])
            tree (head)
        tree2(root,[])
        k=root
        while k.left!=None:k=k.left
        first=k
        while k.right!=None:
            k.right.left=k
            k=k.right
        k.right=first
        first.left=k
        return first
```
