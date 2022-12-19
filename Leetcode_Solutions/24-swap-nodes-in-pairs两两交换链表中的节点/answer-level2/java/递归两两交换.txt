把两两为组断链，然后递归交换后接链 代码如下：

	class Solution {

   	public static ListNode swapPairs(ListNode head) {
        if(head==null){
            return null;
        }
        if(head.next==null){
            return head;
        }
		ListNode h=new ListNode(0);
		swap(h, head, head.next);
		
		return h.next;
	}
	
	public static void swap(ListNode h,ListNode l1,ListNode l2) {
		if(l1.next.next!=null&&l2.next.next!=null) {
			//递归传入尾节点和下一组节点
			swap(l1,l1.next.next,l2.next.next);
			//交换
			l2.next=l1;
			h.next=l2;
		}else {
			//奇数个时挂在后面
            if(l1.next.next!=null){
                l1.next=l1.next.next;
            }else{
               l1.next=null; 
            }
			l2.next=l1;
			h.next=l2;
		}
	}
	}