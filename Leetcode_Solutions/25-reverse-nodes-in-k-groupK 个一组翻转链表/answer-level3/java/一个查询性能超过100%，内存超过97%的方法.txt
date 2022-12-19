使用双指针的方式，一个指针先游走k个位置，判断是否需要反转，然后通过另一个指针来进行实际的移动操作。
 public ListNode reverseKGroup(ListNode head, int k) {
		if (head == null)
			return null;
		ListNode top = head;
		ListNode tail = head;
		int i = 0;
		while (tail != null) {
			i++;
			if (i == k) {
				break;
			}
			tail = tail.next;
		}
		if (i < k)
			return top;
		if (i == k) {
			ListNode node1=tail.next;
			revers(top, 1, k);
			top.next = reverseKGroup(node1, k);
		}
		return tail;
	}

	private ListNode revers(ListNode top, int m, int k) {
		if (m < k) {
			ListNode node = revers(top.next, ++m, k);
			node.next = top;
		}
		return top;
	}