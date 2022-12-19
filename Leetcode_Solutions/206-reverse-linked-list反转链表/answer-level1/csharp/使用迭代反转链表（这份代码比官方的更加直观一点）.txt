
```
    public ListNode ReverseList(ListNode head) {
        ListNode prev = null;
        ListNode curr = head;
            while (curr!=null)
            {
                ListNode temp = curr;
                curr = curr.next;
                temp.next = prev;
                prev = temp;
            }
        return prev;
    }
```
