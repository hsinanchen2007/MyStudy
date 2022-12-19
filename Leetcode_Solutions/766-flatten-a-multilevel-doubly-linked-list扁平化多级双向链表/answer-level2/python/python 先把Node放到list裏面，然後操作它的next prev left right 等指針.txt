```
def bfs(root, rev):
    if root is not None:
        rev.append(Node(root.val, None, None, None))
        bfs(root.child, rev)
        bfs(root.next, rev)
        
class Solution(object):
    def flatten(self, head):
        """
        :type head: Node
        :rtype: Node
        """
        rev = []
        bfs(head, rev)
        if not rev:
            return None

        for i in range(len(rev) - 1):
            rev[i].next = rev[i+1]
            rev[i+1].prev = rev[i]
        return rev[0]

```
好像有好几个题目了，要根据某个遍历方式重构树（这个是bfs序列重构所谓链表）。