    public boolean isPalindrome(ListNode head) {
        if(head == null || head.next == null) {
        	return true;
        }
		ListNode pl = head;
		ListNode pr = head.next;
		//寻找中位点
		while(pr != null && pr.next != null) {
			pl = pl.next;
			pr = pr.next.next;
		}
		
		pr = reverse(pl.next);	//右侧链表头节点
		pl.next = pr;
		pl = head;		//左侧链表头节点
		ListNode cur1 = head;
		ListNode cur2 = pr;
		while(cur2 != null) {
			if(cur1.val != cur2.val) {
				return false;
			}
			cur1 = cur1.next;
			cur2 = cur2.next;
		}
 		return true;
    }

	private ListNode reverse(ListNode head) {
		//链表反转
		ListNode pre = null;
		ListNode cur = head;
		while(cur != null) {
			ListNode next = cur.next;
			cur.next = pre;
			pre = cur;
			cur = next;
		}
		return pre;
	}