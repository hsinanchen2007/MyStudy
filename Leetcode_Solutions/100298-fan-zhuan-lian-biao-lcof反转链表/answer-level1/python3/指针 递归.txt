```
# 定义一个函数，输入一个链表的头节点，反转该链表并输出反转后链表的头节点。

# 示例:
# 输入: 1->2->3->4->5->NULL
# 输出: 5->4->3->2->1->NULL
class ListNode():
    def __init__(self,x=None):
        super().__init__()
        self.val = x
        self.next = None

def resverseList(head):
    curr = head
    pre = None
    next = None
    while curr:
        next = curr.next
        curr.next = pre
        pre = curr
        curr = next
    return pre

def recursiveMethod(head):
    if not head or not head.next:
        return head
    ret = recursiveMethod(head.next)
    head.next.next = head #从倒数第二个节点开始，让下一个节点的指针指向本身，下一个节点的next指向None
    head.next = None
    return ret #ret是最后一个节点的位置

if __name__ == "__main__":
    head = ListNode(1)
    n1 = ListNode(2)
    n2 = ListNode(3)
    head.next = n1
    n1.next = n2

    p = recursiveMethod(head)

    while p:
        print(p.val)
        p = p.next
```
