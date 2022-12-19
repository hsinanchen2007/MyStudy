Suppose we have two pointers both starting at the head of the linked list. 
One is a fast pointer, moving forward by two steps each iteration. 
The other is a slow pointer and moves forward one step a time.

When the fast pointer reaches to none or the last node of the list, both pointers stop.
The slow pointer would now point to the node we want -- 
the middle node if there are odd number of nodes in the list,
or the one after the middle point if there are even number of nodes in the list.

The code:

 def middleNode(self, head: ListNode) -> ListNode:
        slow, fast = head, head
        while fast is not None and fast.next is not None:
            fast = fast.next.next
            slow = slow.next
        return slow


