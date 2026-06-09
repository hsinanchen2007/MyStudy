```
public static void reorderList(ListNode head) {
    /*快指针*/
    ListNode fast = head;
    /*慢指针*/
    ListNode slow = head;
    /*中间节点的前一个节点*/
    ListNode pre = null;
    /*找出中间节点以及其它节点*/
    while (fast != null && fast.next != null) {
      fast = fast.next.next;
      pre = slow;
      slow = slow.next;
    }
    if (slow != null && pre != null) {
      /*把链表从中间节点分开*/
      pre.next = null;
      /*预留遍历循环中的前一个节点*/
      ListNode p = null;
      /*把中间后面部分的节点翻转*/
      while (slow != null) {
        /*先把当前节点的后一个节点存起来*/
        ListNode next = slow.next;
        /*当前节点的下一个节点指向预留遍历循环中的前一个节点*/
        slow.next = p;
        /*预留循环的前一个节点*/
        p = slow;
        /*slow指向自己的下一个节点*/
        slow = next;
      }
      /*定义一个指针重新从头指针开始*/
      ListNode restart = head;
      /*依次将中间后面部分的节点放到前面节点后面*/
      while (restart != null) {
        /*预留后半段的下一个节点*/
        ListNode pNextTemp = p.next;
        /*预留前半段的下一个节点*/
        ListNode rNextTemp = restart.next;
        /*如果前半部分遍历时下一个节点不为空，则可以赋值给后半部分遍历时的下一个节点*/
        if (restart.next != null) {
          p.next = restart.next;
        }
        /*前半部分下个节点指向后半部分的节点*/
        restart.next = p;
        /*后半部分的指向自己的下一个*/
        p = pNextTemp;
        /*前半部分的指向自己的下一个*/
        restart = rNextTemp;
      }
    }
    /*总体思想是：1.找出链表的中间节点；2.将链表截断，后半部分的链表翻转；3.将前半段与翻转的后半段按题目要求翻转*/
  }
```
