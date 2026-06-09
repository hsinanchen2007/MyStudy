```
/**
	 * 这个题目简单的，我看了好几遍，怀疑我是否没看懂题目
	 * 
	 * @param head
	 * @param x
	 * @return
	 */
	public ListNode partition(ListNode head, int x) {
		ListNode befor = new ListNode(0);
		ListNode after = new ListNode(0);

		ListNode beforNode = befor;
		ListNode afterNode = after;

		ListNode node = head;
		while (node != null) {
			if (node.val < x) {
				beforNode.next = node;
				beforNode = node;

			} else {
				afterNode.next = node;
				afterNode = node;

			}
            node=node.next;

		}
		beforNode.next = after.next;
        afterNode.next=null;
		return befor.next;

	}
```
