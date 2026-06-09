```
class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        dic = {}
        if head == None: return None 
        root = head 
        while head:
            if head not in dic:
                dic[head] = 0
                tmp = Node(head.val)
                tmp.next = head.next 
                head.next = tmp 
            if head.random:
                if head.random not in dic:
                    tmp = Node(head.random.val)
                    tmp.next = head.random.next 
                    head.random.next = tmp
                    head.next.random = tmp 
                    dic[head.random] = 0
                else:
                    head.next.random = head.random.next
            head = head.next.next
        res = root = root.next 
        while root:
            if root.next : root.next = root.next.next
            root = root.next 
        return res  
```
