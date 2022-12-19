   public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        StringBuilder num1 = new StringBuilder();
        StringBuilder num2 = new StringBuilder();
        while (l1 != null) {
            num1.append(l1.val);
            l1 = l1.next;
        }
        while (l2 != null) {
            num2.append(l2.val);
            l2 = l2.next;
        }
        BigInteger i = (new BigInteger(num1.toString())).add(new BigInteger(num2.toString()));
        String str = i + "";
        ListNode ans = new ListNode(-1);
        ListNode iter = ans;
        for (int j = 0; j < str.length(); j++) {
            iter.next = new ListNode(str.charAt(j) - '0');
            iter = iter.next;
        }

        return ans.next;
    }