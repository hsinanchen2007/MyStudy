思路很简单，引入一个哑节点，新开辟一个链表，循环老链表，将符合规则的节点移动至新链表上。
这里有个坑，直接把节点移动到新链表上时，节点关系还在，所以需要断链。这是最大的一个坑，要想好在哪里断链。
我是在构造完新链表，最后断链，附上代码：
```
public ListNode removeElements(ListNode head, int val) {
        if (head == null) {
            return null;
        }

        ListNode newNode = new ListNode();
        ListNode currNode = newNode;

        while (head != null) {
            if (head.val != val) {
                // appen到新的链表上
                currNode.next = head;
                // 指向最后一个节点
                currNode = currNode.next;
            }

            // 指向下一个节点
            head = head.next;
        }

        currNode.next = null;
        return newNode.next;
    }
```

