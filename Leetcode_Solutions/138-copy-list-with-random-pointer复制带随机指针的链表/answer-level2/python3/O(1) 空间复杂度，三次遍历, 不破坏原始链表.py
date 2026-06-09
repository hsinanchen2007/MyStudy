class Solution:
    def copyRandomList(self, head: 'Node') -> 'Node':
        if not head: return head
        
        cur = head
        #每个节点后面挂了一个同值的节点
        while cur:
            nxt = cur.next
            cur.next = Node(cur.val)
            cur.next.next = nxt
            cur = cur.next.next
        
        cur = head
        while cur:
            random = cur.random
            #原节点的下一个节点，即为克隆后的的新节点
            if random:
                cur.next.random = random.next
            cur = cur.next.next
        
        #分离两个节点
        #转化为奇偶链表的解法 https://leetcode-cn.com/problems/odd-even-linked-list/
        dummy_odd = odd = head
        dummy_even = even = head.next
        
        odd.next = None
        while even and even.next:
            odd.next = even.next
            odd = odd.next
            even.next = even.next.next
            even = even.next
        
        return dummy_even