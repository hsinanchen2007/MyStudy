题目要求常数空间，其实就是在鼓励我们用迭代。因为递归可能会有压栈操作，导致空间复杂度增加。

我的做法是先获取链表的长度，**确定要进行（k个一组的）迭代的次数**（要进行翻转操作的分组数）；每次迭代翻转k个节点。每次迭代的过程其实就是“翻转链表”的过程，要操作的指针（节点）有当前节点p、p的前一个节点pre、p的后一个节点nextNode，以及为了连接各个翻转的分组而记录的上一组翻转后的末尾节点lastEnd， 还要记录新链表的头节点（第一个分组的末尾节点）。

每k个一组之间的连接尤为重要：lastEnd节点在第一组翻转完毕后开始保存，第二组翻转完毕后接上第二组的头节点（原来的尾），然后lastEnd移位至第二组的尾节点。
```java
public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null || k <= 0) {
            return head;
        }
        //下面数行确定链表的长度和要翻转的分组数
        int length = 0;
        ListNode p = head;
        while (p != null) {
            ++length;
            p = p.next;
        }
        int times = length / k;
        //反转的准备工作，注意特殊的用于连接各个分组（k个一组）的LastEnd节点，以及新链表的头节点
        p = head;
        ListNode newHead = null;
        //lastEnd是迭代时上一组的头节点，也就是上一组反转后的末尾节点，在第二组反转结束时才开始起作用
        ListNode lastEnd = null;
        for (int i = 0; i < times; ++i) {
            ListNode tmp = p;   //tmp节点用于保存当前组的头节点，留待本次反转后更新lastEnd
            ListNode pre = null;
            ListNode nextNode = null;
            //每组反转的核心，与“反转链表”题基本一致
            for (int j = 0; j < k; ++j) {
                nextNode = p.next;
                p.next = pre;
                pre = p;
                p = nextNode;
            }
            if (i == 0) {
                newHead = pre;  //此时pre指针恰好指向原第一组的尾节点，成为新链表的头
            }
            //第二组翻转结束后，第一组的尾结点（原来的头）接上第二组的头（原来尾节点）
            if (lastEnd != null) {  
                lastEnd.next = pre;
            }
            lastEnd = tmp;  //第一组翻转结束时，lastEnd的位置便修改为第一组的尾结点（原来的头）
        }
        //最后可能有多余的节点，要把最后一组翻转的尾节点接上去
        lastEnd.next = p;

        return newHead;
    }
```

时间复杂度：O(n)，准确来说是O(2n)
空间复杂度：O(1)
