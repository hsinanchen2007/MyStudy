        	public ListNode oddEvenList(ListNode head) {
        if(head == null) {
        	return null;
        }
        int m = 1;	//辅助变量   用于判断位次的奇偶性
		ListNode odd_head = new ListNode(0);
		ListNode even_head = new ListNode(0);
		ListNode odd = odd_head;
		ListNode even = even_head;
		//遍历链表
		ListNode cur = head;
		while(cur != null) {
			if(m % 2 != 0) {
				odd.next = cur;
				odd = odd.next;
			}else {
				even.next = cur;
				even = even.next;
			}
			cur = cur.next;
			m += 1;
		}
		even.next = null;
		odd.next = even_head.next;
		return odd_head.next;
    }