从头节点开始，新建链表对象，然后采用头插法，重新插入链表
public ListNode reverseList(ListNode head) {
        ListNode rev = head ;
		ListNode temp , result ;
		if(rev!= null) {
			result = new ListNode(rev.val) ;
			rev = rev.next ;
			while(rev != null) {
				temp = new ListNode(rev.val) ;
				temp.next = result ;
				result = temp ;
				rev = rev.next ;
			}
			return result ;	
		}
		else
			return head ;
    }