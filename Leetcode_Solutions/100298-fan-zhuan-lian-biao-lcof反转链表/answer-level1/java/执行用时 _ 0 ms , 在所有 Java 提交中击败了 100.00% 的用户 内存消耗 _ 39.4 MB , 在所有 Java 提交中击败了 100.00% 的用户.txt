	 ListNode reverse(ListNode head) {
		ListNode prev = null;

		ListNode nexthead = head;

		ListNode next = null;
		while (nexthead != null) {

			next = nexthead.next;
			nexthead.next = prev;
			prev = nexthead;
			nexthead = next;
		}

		return prev;
	}