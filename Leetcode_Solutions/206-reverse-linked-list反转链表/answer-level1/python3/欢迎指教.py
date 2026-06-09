是不是只有第一次写题解才有积分。
class Solution:
    def reverseList(self, head: ListNode) -> ListNode:
        # 如果输进来就是None，返回None
        if not head:
            return None
        
        tmp = list()
        while head:
            tmp.append(head.val)
            head = head.next

        print(tmp)
        ret = ListNode(tmp.pop())
        pointer = ret
        while len(tmp):
            pointer.next = ListNode(tmp.pop())
            pointer = pointer.next

        return ret