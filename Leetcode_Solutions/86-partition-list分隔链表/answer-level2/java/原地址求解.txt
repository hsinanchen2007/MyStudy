可以找第一个大于等于x的结点，记为firstBig，然后在原地址上改变连接
```
class Solution {
    public ListNode partition(ListNode head, int x) {
		ListNode pre = new ListNode(-1);
		pre.next = head;
		ListNode p = pre,firstBig = null;
    while(p.next!=null) {
         p = p.next;
    	if(p.val>=x) {
    		firstBig = p;
    		break;
    	}else {
    		pre = p;
    	}
    }
    while(p!=null&&p.next!=null) {
    	if(p.next.val<x) {
            if(pre.next==head){head = p.next};
    		pre.next = p.next;
            p.next = p.next.next;
    		pre = pre.next;
    		pre.next = firstBig;
    	}
        else p = p.next;
    }
    return head;
  }
}
```


