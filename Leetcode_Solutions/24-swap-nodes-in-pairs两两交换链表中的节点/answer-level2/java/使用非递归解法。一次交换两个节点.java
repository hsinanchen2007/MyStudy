首先设计了一个将两个节点交换位置的函数。在使用函数的时候因为Java采用了引用传递，当函数中的参数在函数体中发生改变之后
，再次使用该参数会发生改变，所以需要将该参数复制给一个变量，将该变量传递给函数。
public class SwapNodes {
	public ListNode swapPairs(ListNode head)
	{
		ListNode headListNode = new ListNode(0);
		headListNode.next=head;
		ListNode beforeListNode=headListNode;
		while(beforeListNode!=null&&beforeListNode.next!=null&&beforeListNode.next.next!=null)
		{
			swapTwoNodes(beforeListNode, beforeListNode.next, beforeListNode.next.next);
			beforeListNode=beforeListNode.next.next;
			//System.out.println(beforeListNode.val+"   "+beforeListNode.next.val+"     "+beforeListNode.next.next.val);
		}
		return headListNode.next;
		
	}
	private void swapTwoNodes(ListNode beforeListNode ,ListNode midListNode,ListNode afterListNode) {
		ListNode tempListNode=null;
		
		tempListNode=afterListNode.next;
		
		beforeListNode.next=afterListNode;
		afterListNode.next=midListNode;
		midListNode.next=tempListNode;
	}
}