解题思路：
首先我们要找到反转区间的开始节点的前驱节点preStartNode，然后记录开始节点为startNode；一共需要反转n -m + 1次将反转区间里的节点全部反转。
循环结束后，判断反转区间是否从链表的头节点开始的：
    如果是，那么只需要将startNode节点的next域置为newHead,返回即可
    如果不是需要拼接新的链表，将preStartNode的next域置为反转过后的首节点，然后反转过后的区间的末节点的next置位newHead
```
比如链表为[1, 2, 3, 4, 5] m = 2, n = 4;那么preStartNode = 1，startNode = 2, 经过3次反转循环后newHead = 5;preNode = 2
此时链表为[1, 4, 3, 2, 5]其中1 -> 2; 2 -> null
preStartNode.next = preNode;
startNode.next = newHead;
后1 -> 4; 2 - 5;

  public ListNode reverseBetween(ListNode head, int m, int n) {
        if (m == n)
            return head;
        ListNode newHead = head;
        ListNode preStartNode = null;
        ListNode preNode = null;
        for (int i = 1; i <= m - 1; i++) {
            preStartNode = newHead;
            newHead = newHead.next;
        }
        ListNode startNode = newHead;
        for (int i = 0; i < n - m + 1; i++){
                ListNode nextNode = newHead.next;
                newHead.next = preNode;
                preNode = newHead;
                newHead = nextNode;
        }
        if (preStartNode != null){
            preStartNode.next = preNode;
            if (newHead == null) {
                return head;
            }
        } else {
            startNode.next = newHead;
            return preNode;
        }
        startNode.next = newHead;
        return head;
    }
```
