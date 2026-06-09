
class Solution:

    def mergeTwoLists(self, l1: ListNode, l2: ListNode) -> ListNode:
        def get_list(param):
            l = []
            cur = param
            while cur != None:
                l.append(cur.val)
                cur = cur.next
                
            return l
        
        
        list1 = get_list(l1)
        list2 = get_list(l2)
        
        list0 = list1 + list2
        
        list0.sort()
        
        
        
        cur = ListNode(0)
        head = cur
        
        for i in range(len(list0)):
            node = ListNode(list0[i])
            cur.next = node
            cur = cur.next
            
        return head.next