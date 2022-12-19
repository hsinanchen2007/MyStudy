```

//给定一个单链表，把所有的奇数节点和偶数节点分别排在一起。请注意，这里的奇数节点和偶数节点指的是节点编号的奇偶性，而不是节点的值的奇偶性。
public ListNode oddEvenList(ListNode head) {
    if (head == null|| head.next ==null) {
		return head;
	}
    ListNode node = head.next;//用该链表遍历
    ListNode insert1 = head;//每次遍历到奇数节点插入到该节点后面并更新insert//可以这样理解，如，指针指向了第二给节点那移动完后，指针向后走，走到的这个节点也需要移动
    ListNode insert2 = head.next;//指向需要被插入位置的前一个节点，即第一个偶节点
//    int index = 1;
    while(node!=null&&node.next!=null) {
    	ListNode now = node.next;//指向需要被移动的节点，将它插入到insert1和insert2之间
    	node.next = node.next.next;//移除now
    	insert1.next = now;
    	now.next = insert2;//将now插入到insert1,insert2之间
    	insert1 = now;//将insert1指向now
    	node = node.next;//后移
    }    
    return head;
}

```
