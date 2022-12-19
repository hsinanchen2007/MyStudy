class Solution {
    public ListNode reverseList(ListNode head) {
        ListNode head2 = new ListNode(0);//创建一个新的链表
        ListNode next = null;//临时变量 用于存储下一个节点
        ListNode cur = head;//从头开始，如果赋值为head.next第一个节点会丢失
        while(cur != null){
            next = cur.next;
        //这两行相当于单链表插入操作，只不过每次插在新链表的头部
        //插入时 相当于在新链表head2的后面和头结点之间插入，所以将cur.next(cur.next相当于箭头)指向head2.next(新链表的头结点)
            //将cur的值与head2.next连接起来
            cur.next = head2.next;
            head2.next = cur;
            //后移
            cur = next;    
        }
        return head2.next;

    }
}