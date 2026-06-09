
思路就在代码里面
```
public ListNode rotateRight(ListNode head, int k) {
		if (head == null)
			return head;
		int sum = 1;
		ListNode tempNode = head;
		/**
		 * 找到最后一个节点，同时计算出链表长度
		 */
		while (tempNode.next != null) {
			tempNode = tempNode.next;
			sum++;
		}
		/**
		 * 构成一个环形链表
		 */
		tempNode.next = head;

		/**
		 * 右转i个，等于左转n-i个，那么直接左移就好了
		 */
		int cursor = sum - (k % sum);

		while (cursor > 1) {
			head = head.next;
			cursor--;
		}
		tempNode = head.next;
		head.next = null;
		return tempNode;

	}

```
