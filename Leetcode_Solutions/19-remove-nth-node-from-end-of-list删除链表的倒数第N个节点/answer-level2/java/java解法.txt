```
public ListNode removeNthFromEnd(ListNode head, int n) {
	ListNode temp = head;
	int length = 1;
	while (temp.next != null) {
		temp = temp.next;
		length++;
	}
	if(n < 0 || n > length)
		return head;
	if(length == 1 && n == 1)
		return null;
	ListNode pre = null;
	temp = head;
	int i = 0;
	while (i++ + n < length) {
		pre = temp;
		temp = temp.next;
	}
	if(pre == null)
		head = temp.next;
	else
		pre.next = temp.next;
	return head;
}
```

