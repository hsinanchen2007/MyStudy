### 解题思路
递归和迭代

```csharp
public ListNode ReverseList(ListNode head) 
{
    if (head == null || head.next == null)
        return head;
    ListNode result = ReverseList(head.next);
    head.next.next = head;
    head.next = null;
    return result;
}

public ListNode ReverseList(ListNode head) 
{
    ListNode pre = null;
    ListNode cur = head;
    while(cur != null)
    {
        ListNode temp = cur.next;
        cur.next = pre;
        pre = cur;
        cur = temp;
    }
    return pre;
}
```
