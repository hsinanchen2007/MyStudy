方法：简单进行一层循环，后一个元素判断与前一个元素是否相同，注意边界条件的控制
head!=null&&head.next!=null,如果有相同的元素，前者的next指针指向后者元素的下一个元素
head.next =head.next.next即可，continue,继续进行一个元素判断,不用进行head=head.next。如果不等，指针移动一位head=head.next;
```
 public ListNode deleteDuplicates(ListNode head) {
        if(head==null) return head;
		 ListNode p =head;
		 while(head!=null&&head.next!=null) {
			if(head.next.val==head.val) {
				head.next= head.next.next;
                continue;
			}
             head =head.next;
		 }
		 
		 return p;
    }
```

