        public ListNode insertionSortList(ListNode head) {
		ListNode dummyHead = new ListNode(0);
		dummyHead.next = head;
		if(head == null || head.next == null) {
			return head;
		}
		ListNode pre = dummyHead.next;
		while(pre.next != null) {
			ListNode p = dummyHead;
			ListNode next = pre.next.next;
			for(; p != pre; p = p.next) {
				if(pre.next.val < p.next.val) {
					ListNode swapNode = pre.next;
					ListNode p2 = p.next;
					
					p.next = swapNode;
					swapNode.next = p2;
					pre.next = next;
					break;
				}			
			}
			if(p == pre) pre = pre.next;
		}
		return dummyHead.next;
    }