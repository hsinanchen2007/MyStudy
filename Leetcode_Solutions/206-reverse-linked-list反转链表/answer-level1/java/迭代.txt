```
// 反转链表,方法一：迭代
	public ListNode reverseList(ListNode head) {
		// 新链表的第一个结点
		ListNode pre = null;
		// 当前结点
		ListNode cur = head;
		while (cur != null) {
			// 临时结点
			ListNode nextTemp = cur.next;
			// cur所指结点指向pre所指结点
			cur.next = pre;
			// pre指向cur(当前最靠前)的结点
			pre = cur;
			// cur指向nextTemp所指结点
			cur = nextTemp;
		}
		return pre;
	}
```
