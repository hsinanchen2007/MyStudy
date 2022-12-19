        public ListNode reverseKGroup(ListNode head, int k) {
        ListNode dummyHead = new ListNode(0);
        dummyHead.next = head;
        ListNode pre = dummyHead;
        while(pre != null && pre.next != null) {
        	int i;
        	ListNode end = pre;
        	for(i = 0; i < k && end.next != null; i ++) {
        		end = end.next;
        	}
        	if(i != k) {	//链表长度小于k
        		break;
        	}
        	ListNode next = end.next;	//这是上次累加后第一个节点
        	ListNode rhead = swap(pre.next,end,k);	//反转后的头节点
        	
        	ListNode tail = pre.next;	//反转后的尾节点
        	pre.next = rhead;
        	tail.next = next;
        	pre = tail;		//调整pre继续循环
        }
		return dummyHead.next;
    }
	private ListNode swap(ListNode head, ListNode end, int k) {
		// 反转k个节点
		ListNode cur = head;
		ListNode pre = null;
		int i = 0;
		while(cur != null && i < k) {
			i ++;
			ListNode next = cur.next;
			cur.next = pre;
			pre = cur;
			cur = next;			
		}		
		return pre;
	}