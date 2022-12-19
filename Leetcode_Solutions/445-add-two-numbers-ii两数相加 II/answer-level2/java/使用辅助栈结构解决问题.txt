    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
		Stack<Integer> stack1 = new Stack<>();
		Stack<Integer> stack2 = new Stack<>();
		while(l1 != null) {
			stack1.push(l1.val);
			l1 = l1.next;
		}
		while(l2 != null) {
			stack2.push(l2.val);
			l2 = l2.next;
		}
		Stack<Integer> stack3 = new Stack<>();
		int k = 0;	//判断是否需要向前进一位
		while(!stack1.isEmpty() || !stack2.isEmpty()) {
			int m = (!stack1.isEmpty()) ? stack1.pop() : 0;
			int n = (!stack2.isEmpty()) ? stack2.pop() : 0;
			int sum = k + m + n;
			k = sum / 10;
			stack3.push(sum % 10);
		}
		if(k > 0) {
			stack3.push(1);
		}
		ListNode new_head = new ListNode(0);
		ListNode cur = new_head;
		while(!stack3.isEmpty()) {
			cur.next = new ListNode(stack3.pop());
			cur = cur.next;
		}
		cur.next = null;
		return new_head.next;
    }