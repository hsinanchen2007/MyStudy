 迭代图解：
![IMG_9206.JPG](https://pic.leetcode-cn.com/2647fbdca22e8e5a7d372321bee7b6142aab46174e52c669675005fcbeab52eb-IMG_9206.JPG)
代码：
public class Solution206 {

	 
		  public ListNode reverseList(ListNode head) {
			  //必须要判断head是否为空，即传进来的链表是否为空，否则报空指针异常
			  if(head==null) {
				  return null;
			  }else {
			//迭代过程中，引用last一直指向反转结束后的最后一个节点(该引用指向的节点在迭代过程中不变 )
				  //例如，传进的是[1,2,3,4],则last始终指向值为1的节点（反转结束前，last 都是名义上的最后一个     节          点，它有着向后的野心！）
			 //current指向需要进行反转操作的当前节点
			  ListNode last=head;
			  ListNode current=last.next;			  
			  while(current!=null) { 
				  
				  last.next=current.next;
				  current.next=head;
				  //维护head，head始终指向链表头
				  head=current;
				  //维护current,current始终指向last下一个节点，直到current 为空，循环结束，此时last终于成为最后一个节点
				  current=last.next;
			  }
			  }
				 return head;	        
		    }
递归图解：
 
![IMG_9208.JPG](https://pic.leetcode-cn.com/4dd5bb61120e93ebd5dbc8981b7e07568f18b4a88677323673be4dde6970903b-IMG_9208.JPG)
代码：

public class Solution206_2 {

	public ListNode reverseList(ListNode head) {
		 if(head==null) {
			   return null;
		   }  
		ListNode last=head;
		ListNode current=last.next;
		  
		   return reverse(head,last,current);
	    }
	  private ListNode reverse(ListNode head, ListNode last, ListNode current) {
		if(current==null) {
			return head;
		}
		last.next=current.next;
		ListNode temp=current.next;
		current.next=head;
		//注意此时reverse方法的参数
		return reverse(current,last,temp);
		
	}
