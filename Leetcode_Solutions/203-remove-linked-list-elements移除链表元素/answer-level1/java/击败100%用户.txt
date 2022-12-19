**思路**：把旧的链表插入到新的链表中（除去等于val的节点）
public ListNode removeElements(ListNode head, int val)
  {
    // 新的链表
    ListNode a = new ListNode(0);
    // 用于循环时移动next指针
    ListNode b = a;
    while (head != null)
    {
      if (head.val == val)
      {
        head = head.next;
        continue;
      } else
      {
        b.next = new ListNode(head.val);
      }
      b = b.next;
      head = head.next;
    }
    return a.next;
  }