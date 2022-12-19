    
```
//利用栈的特性  
    public ListNode reverseList(ListNode head) {
        Stack<Integer> stack = new Stack<>();
        ListNode p = head;
        while (p != null) {
            stack.push(p.val);
            p = p.next;
        }
        //声明头节点
        ListNode newList = new ListNode(0);
        //用来移动指针的节点
        ListNode mark = newList;
        if (stack != null && stack.size() > 0) {
            int size = stack.size();
            for (int i = 0; i < size; i++) {
                mark.next = new ListNode(stack.pop());
                mark = mark.next;
            }
        }
        return newList.next;
    }
```
