```
public ListNode rotateRight(ListNode head, int k) {//让该链表直接连成环然后从某一个位置断开即相当于旋转
    if(head == null||head.next == null||k==0) {
    	return head;
    }
    ListNode end  = head;
    int len = 0;
    while (end.next!=null) {//end指向最后一个,pre指向倒数第二个
		end = end.next;
		len++;
	}
    len = len+1;//长度为这个
    end.next = head;//连接成环状
    k = k%len;//减少遍历次数
    int times = len - k;//寻找次数
    for (int i = 0; i < times; i++) {
		end = end.next;
	}
    //断开节点
    head = end.next;
    end.next = null;
    return head;   
}
```