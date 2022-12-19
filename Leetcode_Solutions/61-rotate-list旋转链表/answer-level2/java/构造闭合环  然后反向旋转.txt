    public ListNode rotateRight(ListNode head, int k) {       
        if(head == null || head.next == null) {
        	return head;
        }
        ListNode pre = new ListNode(0);
        pre.next = head;
        int nums = 0;	//链表长度
		while(pre.next != null) {
			nums ++;
			pre = pre.next;
		}
		pre.next = head;	//将链表头尾相连
		
		ListNode rhead = head;	//定义为旋转后的头节点 初始化为head
		int n = nums - (k % nums);	//链表需要向下旋转几位
		while(n > 0) {
			rhead = rhead.next;
			n --;
		}
		//此时循环结束的rhead为旋转后的头节点
		//寻找此时的尾节点 链表长度固定
		ListNode fina = rhead;
		while(nums > 1) {
			fina = fina.next;
			nums --;
		}
		//fian代表此时的尾节点
		fina.next = null;
		return rhead;
    }