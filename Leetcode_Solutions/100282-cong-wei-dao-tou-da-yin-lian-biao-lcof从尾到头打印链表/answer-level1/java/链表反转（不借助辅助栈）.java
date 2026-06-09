```
```
代码块（不借助辅助栈，将链表结点原地逆序）
	public int[] reversePrint2(ListNode head) {
		int length = 0;
		ListNode newHead = null;
		while (head != null) {
			ListNode next = head.next;
			head.next = newHead;
			newHead = head;
			head = next;
			length++;
		}
		int[] arr = new int[length];
		int index = 0;
		while (head != null) {
			arr[index++] = head.val;
			head = head.next;
		}
		return arr;
	}
```

```
