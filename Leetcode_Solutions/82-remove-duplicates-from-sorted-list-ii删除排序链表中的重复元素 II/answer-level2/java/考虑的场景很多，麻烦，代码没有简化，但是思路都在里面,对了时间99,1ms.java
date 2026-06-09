```
 public ListNode deleteDuplicates(ListNode head) {
		if (head == null)
			return null;
		if (head.next == null)
			return head;

		/**
		 * 先获取到头结点
		 */
		ListNode node = head;
		ListNode nodeTemp = head;
		boolean isGet = false;
		ListNode newHead = head;
		while (node != null) {
			ListNode temp = node.next;
			if (temp == null) {
				if (!isGet) {
					if (nodeTemp == node) {
						isGet = true;
						newHead = nodeTemp;
					}

				} else {
					if (nodeTemp.next != node) {
						nodeTemp.next = null;
					}
				}
				break;
			}
			if (temp.val == node.val) {
				node = temp;
			} else {
				if (!isGet) {
					/**
					 * 没确定头结点
					 */
					if (nodeTemp == node) {
						isGet = true;
						nodeTemp = node;
						node = temp;
						newHead = nodeTemp;
					} else {
						nodeTemp = temp;
						node = temp;
					}

				} else {
					if (nodeTemp.next == node) {
						nodeTemp = node;
						node = temp;
					} else {
						nodeTemp.next = temp;
						node = temp;

					}

				}
			}

		}
		if (!isGet)
			return null;

		return newHead;

	}
```
