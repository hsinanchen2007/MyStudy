递归解法 先给长度短的补上0
```
    int carry = 0;
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {   //递归做法 给长度少的补0
        if (l1==null)
            return l2;
        if (l2==null)
            return l1;
        int length1 = 0;
        int length2 = 0;
        ListNode node = l1;
        while (node!=null){
            length1++;
            node = node.next;
        }
        node = l2;
        while (node!=null){
            length2++;
            node = node.next;
        }
        ListNode out ;
        if (length1!=length2){
            ListNode listNode = new ListNode(0);
            ListNode go =listNode;
            int count = Math.abs(length1-length2)-1;
            while (count>0){
                listNode.next = new ListNode(0);
                listNode = listNode.next;
                count--;
            }
            listNode.next = length1>length2?l2:l1;
            if (length1>length2){
                out  = add(l1,go);
            }else {
                out = add(go,l2);
            }
        }else
            out =  add(l1,l2);
        if (carry!=0){
            ListNode carryNode = new ListNode(carry);
            carryNode.next = out;
            out = carryNode;
        }
        return out;
    }
    public ListNode add(ListNode l1, ListNode l2){
        int val;
        if (l1.next==null&&l2.next==null){
             val = l1.val + l2.val;
        }else {
            addTwoNumbers(l1.next,l2.next);
            val = l1.val + l2.val + carry;
        }
        carry = val / 10; //计算进位
        val = carry==0?val:val-10; //该位的最终表示
        l1.val = val;
        return l1;
    }
```
利用栈迭代做法 当栈无数据时用0代替
```
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        if (l1==null)
            return l2;
        if (l2==null)
            return l1;
        Stack<Integer> stack1 = new Stack<>();
        Stack<Integer> stack2 = new Stack<>();
        int carry = 0;
        while (l1!=null){
            stack1.add(l1.val);
            l1 = l1.next;
        }
        while (l2!=null){
            stack2.add(l2.val);
            l2 = l2.next;
        }
        ListNode  out = null;
        while (!(stack1.isEmpty()&&stack2.isEmpty())){
            int n1 = stack1.isEmpty()?0:stack1.pop();
            int n2 = stack2.isEmpty()?0:stack2.pop();
            int sum = n1 + n2 + carry;
            carry = sum / 10;
            if (sum>9){
                sum = sum - 10;
            }
            ListNode node = new ListNode(sum);
            node.next = out;
            out = node;
        }
        if (carry!=0){
            ListNode carryNode = new ListNode(carry);
            carryNode.next = out;
            out = carryNode;
        }
        return out;
    }
```

