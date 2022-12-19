每次检查链表是否存在前两个元素，存在就交换

执行用时 :44 ms, 在所有 Python3 提交中击败了91.16%的用户
内存消耗 :13.9 MB, 在所有 Python3 提交中击败了5.93%的用户


```python [class Solution:
    def swapPairs(self, head: ListNode) -> ListNode:
        dummyhead=ListNode(0)
        dummyhead.next=head
        p=dummyhead
        def gen(p):
            
            if p.next!=None and p.next.next!=None:
                q=p.next
                p.next=p.next.next
                q.next=p.next.next
                p.next.next=q
                p=p.next.next
                gen(p)
        gen(p)
        return dummyhead.next]

```
