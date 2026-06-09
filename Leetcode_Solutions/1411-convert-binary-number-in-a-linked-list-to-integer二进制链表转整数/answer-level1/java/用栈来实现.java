 public int getDecimalValue1(ListNode head) {
        Stack<ListNode> stack = new Stack<>();
        while (head != null) {
            stack.push(head);
            head = head.next;
        }
        int sum = 0;
        int i = 0;
        while (!stack.empty()) {
            ListNode pop = stack.pop();
            sum += pop.val * Math.pow(2, i);
            i++;
        }
        return sum;
    }