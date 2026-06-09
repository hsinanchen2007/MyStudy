```
# 148. 排序链表
# 在 O(n log n) 时间复杂度和常数级空间复杂度下，对链表进行排序。

# 示例 1:

# 输入: 4->2->1->3
# 输出: 1->2->3->4
# 示例 2:

# 输入: -1->5->3->4->0
# 输出: -1->0->3->4->5
#-归并排序 需要两个操作 merge合并两个链表   cut返回等分截断后两个子链表的头（注意first_tail.next = None）
class ListNode():
    def __init__(self,x=None):
        super().__init__()
        self.val = x
        self.next = None

def show(head):
    while head:
        print(head.val)
        head = head.next

class Solution:
    def cut(self,h): #从中间阶段链表，返回两个头 一种方式fast先走一步，mid = slow.next slow.next = None
        fast = h.next
        slow = h
        while fast and fast.next:
            slow = slow.next
            fast = fast.next.next
        mid = slow.next 
        slow.next = None
        return h,mid
    
    def cutt(self,head):
        pre,slow,fast = None,head,head
        while fast and fast.next:
            pre,slow,fast = slow,slow.next,fast.next.next
        mid = slow
        pre.next = None
        return head,mid
    def merge(self,h1,h2):

        dummyHead = ListNode(0)
        cur = dummyHead
        while h1 and h2:
            if h1.val <= h2.val:
                cur.next,h1 = h1,h1.next
            else:
                cur.next,h2 = h2,h2.next
            cur = cur.next
        cur.next = h1 if h1 else h2
        return dummyHead.next

    def sortList(self, head: ListNode) -> ListNode:
        
        if not head or not head.next:
            return head
        
        h1,h2 = self.cutt(head)
        return self.merge(self.sortList(h1), self.sortList(h2))

n1 = ListNode(2)
n2 = ListNode(1)
n3 = ListNode(3)
n1.next = n2
n2.next = n3
show(Solution().sortList(n1))
```
