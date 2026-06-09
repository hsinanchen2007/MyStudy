    public ListNode AddTwoNumbers(ListNode l1, ListNode l2,int carry=0){
        //return condition
        if (l1 == null && l2 == null) {
            if (carry == 0) return null;
            else return new ListNode(1);
        }

        l1 = l1 ?? new ListNode(0); l2 = l2 ?? new ListNode(0);
        var val = l1.val + l2.val+carry;
        var node=new ListNode(val%10);
        node.next = AddTwoNumbers(l1.next, l2.next, val / 10);

        return node;
    }