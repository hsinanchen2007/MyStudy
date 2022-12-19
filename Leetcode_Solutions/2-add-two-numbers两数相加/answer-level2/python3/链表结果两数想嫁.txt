1，先判断其中一个链表为空情况
2，两个链表想加，要遍历长度应该是最长链表长度+1，因为极端情况，一直有进位
3，最后一位还是有进位的话，新建立节点存储进位1
4，短链表，后面空节点val值当作为0

```python []
# Definition for singly-linked list.
class ListNode:
    def __init__(self, x):
        self.val = x
        self.next = None


class Solution:
    def addTwoNumbers(self, l1: ListNode, l2: ListNode) -> ListNode:
        if not l1:
            return l2
        elif not l2:
            return l1
        front_val = 0
        head = None
        while l1 or l2:
            v1 = l1.val if l1 else 0
            v2 = l2.val if l2 else 0
            sum_val = (v1 + v2) + front_val
            if 0 <= sum_val <= 9:
                tail = ListNode(sum_val)
                front_val = 0
            else:
                tail = ListNode(sum_val % 10)
                front_val = 1
            if head == None:
                head = tail
                current = head
            else:
                current.next = tail
                current = current.next
            l1 = l1.next if l1 else None
            l2 = l2.next if l2 else None
        if front_val > 0:
            tail = ListNode(front_val)
            current.next = tail
            current = current.next
        return head


if __name__=="__main__":
    # l1=[2,4,3,9,8]

    l1=ListNode(2)
    l1_2=ListNode(4)
    l1_3=ListNode(3)
    l1_4=ListNode(9)
    l1_5=ListNode(8)
    l1.next=l1_2
    l1_2.next=l1_3
    l1_3.next=l1_4
    l1_4.next=l1_5
    # l2=[5,6,4]
    l2=ListNode(5)
    l2_2=ListNode(6)
    l2_3=ListNode(4)
    l2.next=l2_2
    l2_2.next=l2_3

    s=Solution()
    node=s.addTwoNumbers(l1,l2)
    while node:
        print(node.val)
        node=node.next


```
