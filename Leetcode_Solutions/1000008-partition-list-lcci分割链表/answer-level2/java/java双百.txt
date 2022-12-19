元素不必保持相同的相对顺序。我们只需要确保小于基准点的元素必须位于比基准点大的元素之前。
 * 所以凡是小于X的节点全部插到头节点之前去。
 * 双指针：dummy用于头插，tail用于尾插
 ```
public ListNode partition(ListNode head, int x) {
		ListNode dummy = new ListNode(-1);
		ListNode tail = dummy;
		ListNode tmp;
		while (head != null) {
			tmp = head.next;
			if (dummy.next != null && head.val < x) {//头插
				head.next = dummy.next;
				dummy.next = head;
			} else {//尾插，包括一开始dummy.next == null的情况
				tail.next = head;
				head.next = null;
				tail = tail.next;
			}
			head = tmp;
		}
		return dummy.next;
	}
```
