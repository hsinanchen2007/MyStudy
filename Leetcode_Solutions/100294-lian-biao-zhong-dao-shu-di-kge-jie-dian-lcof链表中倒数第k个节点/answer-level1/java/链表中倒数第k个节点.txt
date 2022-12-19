这里主要考察到了快慢指针的用法，可以先让快指针先走k步，然后快慢指针一起走，当快指针到链表尾部时，就得出结果

```java
    /**
    * 使用快慢指针求解，慢指针让快指针先走 k 步，然后在一起走
    */
    public ListNode getKthFromEnd(ListNode head, int k) {
        if (head == null) {
            return null;
        }
        ListNode slow = head, fast = head;
        while (fast != null) {
            if (k == 0) {  // k == 0时，即快指针走完了，再一起走
                slow = slow.next;    
            } else {
                k--;
            }
            fast = fast.next;
        }
        return slow;
    }
```

不过一开始用了比较戳的办法，两个栈 + 链表来求解，这样效率太低
```java
/**
    * 用两个栈 + 一个链表来实现
    */
    public ListNode getKthFromEnd(ListNode head, int k) {
        if (head == null) {
            return null;
        }
        // 设置一个伪头结点，用于存储最终的结果
        ListNode summaryNode = new ListNode(0), pre = summaryNode;
        // 定义栈和反转栈
        Stack<Integer> stack = new Stack<Integer>();
        Stack<Integer> reverseStack = new Stack<Integer>();

        // 先存储当前链表进栈
        while (head != null) {
            stack.push(head.val);
            head = head.next;
        }
        // 对k进行处理
        for (int i = 0; i < k; i++) {
            if (stack.isEmpty()) {
                return null;
            }
            reverseStack.push(stack.pop());
        }
        while (!reverseStack.isEmpty()) {
            summaryNode.next = new ListNode(reverseStack.pop());
            summaryNode = summaryNode.next;
        }
        return pre.next;
    }
```