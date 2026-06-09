```
public ListNode reverseBetween(ListNode head, int m, int n) {
		 int change_len = n - m + 1; //计算需要逆置的节点个数
		 ListNode pre_head = null; //指向第一个逆置节点的前驱节点
		 ListNode result = head; //最终转换后的链表头结点，非特殊情况即为head
		 while(head != null && --m != 0) {
			 pre_head = head;
			 head = head.next;  // 此时 head 值指向逆置区间的首节点
		 }
		 ListNode tail = head; //指向逆置后的逆置区间的尾节点
		 ListNode new_head = null;  //指向逆置后的逆置区间的首节点
		 while(head != null && change_len != 0) {
			 ListNode next = head.next;
			 head.next = new_head;
			 new_head = head;
			 head = next;
			 change_len--;
		 }  // 此时 head 指向逆置区间的后一个节点
		 tail.next = head; //逆置结束，连接逆置区间的链表尾与逆置段的后一个节点
		 if(pre_head != null) { //说明 m > 1
			 pre_head.next = new_head;  //将逆置后的逆置区间的首节点的前驱节点与首结点连接
		 }else {
			 result = new_head; //说明 最开始的while没执行，m == 1 , 则结果链表的头结点就是逆置区间的首节点
		 }
		 return result;
    }
```
