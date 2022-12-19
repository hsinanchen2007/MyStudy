```python
class Solution:
    def treeToDoublyList0(self, root: 'Node') -> 'Node':
        if not root: return 

        def recur(root, last):
            if not root: return last 
            last = recur(root.left, last)
            if last: last.right = root
            root.left = last 
            last = root
            last = recur(root.right, last)
            return last 
        
        last = tail = recur(root, None)
        while last.left:
            last = last.left
        last.left = tail
        tail.right = last
        return last 

    def treeToDoublyList1(self, root: 'Node') -> 'Node':
        if not root: return 

        def recur(root):
            if not root: return None, None
            left_min, left_max = recur(root.left)
            right_min, right_max = recur(root.right)
            root.left = left_max
            if left_max: left_max.right = root
            root.right = right_min
            if right_min: right_min.left = root
            return left_min if left_min else root, right_max if right_max else root 

        head, tail = recur(root)
        head.left = tail
        tail.right = head
        return head

    def treeToDoublyList2(self, root: 'Node') -> 'Node':
        if not root: return 
        q = []
        cur = root
        dummy = node = Node(None)
        while q or cur:
            while cur:
                q.append(cur)
                cur = cur.left
            next_ = q.pop()
            node.right = next_
            node = node.right
            cur = next_.right

        pre = next_
        cur = dummy.right
        while cur:
            cur.left = pre
            pre, cur = cur, cur.right
        pre.right = dummy.right
        return dummy.right
```