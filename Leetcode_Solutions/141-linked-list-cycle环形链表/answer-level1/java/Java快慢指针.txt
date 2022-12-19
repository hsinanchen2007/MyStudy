```
  public boolean hasCycle(ListNode head) {
        if(head == null || head.next == null) return false; //如果是空结点或只有一个结点
	        ListNode slow = head;   // 慢指针
	        ListNode fast = head.next; //   快指针
	        while(fast!=null&& fast.next != null){ //快指针没有到链表尾部，环形是没有尾部的
	        	slow = slow.next;    //慢指针一步
	        	fast = fast.next.next;  //快指针两步
	        	if(slow == fast) return true;   //两个指针指向同一个，则是环形链表
	        }
	        return false;    //如果不是环形，返回fasle
    }
```
我是菜鸟，请多交流