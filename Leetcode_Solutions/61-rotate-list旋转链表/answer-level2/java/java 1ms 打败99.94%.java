找到倒数的点，然后拼接到头部
这道题特殊，k可能会超过链表的长度，当超过长度的时候相当于回头了。
所以需要先遍历一遍拿到链表长度
```java
	public ListNode rotateRight(ListNode head, int k) {
		if (head == null || head.next == null || k <= 0) {
			return head;
		}
		int length = 1;
		ListNode temp = head;
		while (temp.next != null) {
			temp = temp.next;
			length++;
		}
		k = k % length;
		if (k == 0) {
			return head;
		}
		ListNode fast = head;
		ListNode slow = head;
		while (k != 0) {
			fast = fast.next;
			k--;
		}
		while (fast.next != null) {
			fast = fast.next;
			slow = slow.next;
		}
		ListNode newHead = slow.next;
		slow.next = null;
		fast.next = head;
		return newHead;
	}
```
