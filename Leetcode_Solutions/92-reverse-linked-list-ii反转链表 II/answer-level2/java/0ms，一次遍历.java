```
 public ListNode reverseBetween(ListNode head, int m, int n) {

		if (m == 1) {
			ListNode node = head;
			ListNode node1 = head.next;
			if (node1 == null)
				return head;
			while (m < n) {
				ListNode temp = node1.next;
				node1.next = node;
				node = node1;
				node1 = temp;
				m++;
			}
			head.next = node1;
			return node;
		} else {
			ListNode newNode = head;
			int cursor = 1;
			while (cursor < m - 1) {
				newNode = newNode.next;
				cursor++;
			}
			

			ListNode node = newNode.next;
			ListNode node1 = newNode.next.next;
			if (node1 == null)
				return head;
			while (m < n) {
				ListNode temp = node1.next;
				node1.next = node;
				node = node1;
				node1 = temp;
				m++;
			}
			newNode.next.next = node1;
			
			newNode.next=node;
			
			return head;
		}

	}
```
