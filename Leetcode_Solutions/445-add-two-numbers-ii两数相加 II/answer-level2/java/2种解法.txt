**反转**

- 1. 将每个链表都进行反转
- 2. 将链表各个节点进行相加
-    - a. 遍历两个链表，分别计算每个节点的和，并把计算的和 sum % 10 插入到一个新的链表中
     - b. 如果相加的和 >10 需要进位的，则把 sum/10 存储下来加入到下个节点的和中
     - c. 如果最后一位相加还需要进位的情况，则直接把余数 post 插入到新链表的末尾即可
     - d. 最后只需要返回虚拟头节点的 dummyHead.next 即可
     - 注意 ：要小心链表大小不一的情况，获取空链表的变量可能会出现 NullPointerException
- 3. 相加之后在进行反转一次即可

- 复杂度分析：
- 时间复杂度：O(max(m , n))， m 和 n 表示两个链表的长度
- 空间复杂度：O(max(m, n) + （(m + n）+ max(m, n)）), 空间复杂度需要将递归的复杂度加上新的节点占用的空间

```
    public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode reverseL1 = reverse(l1);
        ListNode reverseL2 = reverse(l2);
        return reverse(add(reverseL1, reverseL2, 0));
    }

    public static ListNode add(ListNode l1, ListNode l2, int post) {
        if (l1 == null && l2 == null && post == 0) return null;
        int x = l1 == null ? 0 : l1.val;
        int y = l2 == null ? 0 : l2.val;
        int sum = x + y + post;
        ListNode node = new ListNode(sum % 10);
        node.next = add(l1 == null ? null : l1.next, l2 == null ? null : l2.next, sum / 10);
        return node;
    }

    public static ListNode reverse(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode node = reverse(head.next);
        head.next.next = head;
        head.next = null;
        return node;
    }

```

**入栈+反转**

- 1. 新建两个栈，并将两个链表的元素一次入栈
  2. 每次出栈栈顶元素相加，步骤同上方法
  3. 最后将新的链表反转一次即可

- 时间复杂度：O(max(m , n))， m 和 n 表示两个链表的长度
- 空间复杂度：O(max(m, n) + (m + n) + max(m, n))

```
public static ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        Stack<ListNode> stack1 = new Stack<>();
        Stack<ListNode> stack2 = new Stack<>();
        ListNode dummyHead = new ListNode(0);
        ListNode prev = dummyHead;
        int mod = 0;
        while (l1 != null) {
            stack1.push(l1);
            l1 = l1.next;
        }
        while (l2 != null) {
            stack2.push(l2);
            l2 = l2.next;
        }
        while (!stack1.isEmpty() || !stack2.isEmpty() || mod != 0) {
            int x = stack1.isEmpty() ? 0 : stack1.peek().val;
            int y = stack2.isEmpty() ? 0 : stack2.peek().val;
            int sum = x + y + mod;
            mod = sum / 10;
            prev.next = new ListNode(sum % 10);
            prev = prev.next;
            if (!stack1.isEmpty()) stack1.pop();
            if (!stack2.isEmpty()) stack2.pop();
        }
        return reverse(dummyHead.next);
    }

    public static ListNode reverse(ListNode head) {
        if (head == null || head.next == null) return head;
        ListNode node = reverse(head.next);
        head.next.next = head;
        head.next = null;
        return node;
    }
```