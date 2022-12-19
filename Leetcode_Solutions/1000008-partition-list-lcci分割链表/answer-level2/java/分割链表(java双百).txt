大体思路：
    先创建两个头结点分别用于连接小于部分和大于等于部分
    遍历该链表，若当前结点小于x,将其插到小于的链表上否则插到大于链表上。
    遍历完毕后，将大于等于部分链表的连到小于部分的后面即可.
```
 public ListNode partition(ListNode head, int x) {
        ListNode preHead = new ListNode(-1);
        ListNode nextHead = new ListNode(-1);
        ListNode preCurrent = preHead, nextCurrent = nextHead, current = head;
        while(current != null){
            if(current.val < x){
                preCurrent.next = current;
                preCurrent = preCurrent.next;
            }else{
                nextCurrent.next = current;
                nextCurrent = nextCurrent.next;
            }
            current = current.next;
        }
        preCurrent.next = nextHead.next;
        nextCurrent.next = null;
        return preHead.next;
    }
```

