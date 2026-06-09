要考虑两种特殊情况，一种是m==1的情况，另一种是n为链表末尾的情况，
当m==1时，最后返回的是n端节点。
当n为链表末尾时，要记得将右断点(即m端)的next置空，否则链表会成环，导致内存超限报错。

付代码:

class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {

        if (m==n) {
			return head;
		}
		int count = 1;
		
		ListNode lastNode = null;
		ListNode currentNode = head;
		ListNode nextNode = null;
		
		ListNode leftBreakPoint = null;
		ListNode rightBreakPoint = null;
		
		ListNode result = null;
		
		while (currentNode!=null) {
		
			if (m - count == 1) {
				leftBreakPoint = currentNode;
			}else if (count == m) {
				rightBreakPoint = currentNode;
			}
			
			if (count==n) {
				//m端边界情况，如果 m端为链表起始点，则应该将n端节点作为返回值。
				if (m==1) {
					result = currentNode;
				}else {
				//否则返回值为head，并且将左断点的next连接至n端。
					leftBreakPoint.next = currentNode;					
				}
				//****************************
				//n端边界情况
				//一定考虑边界情况，如果n后没有节点，则要记得将右断点的next置空，否则链表会成环，导致内存溢出
				if (currentNode.next==null) {
					rightBreakPoint.next = null;
				}
				//****************************
			}else if (count-n==1) {
				rightBreakPoint.next = currentNode;
			}
			
			nextNode = currentNode.next;
			
			if (count>m && count<=n) {
				currentNode.next = lastNode;
			}
			
			lastNode = currentNode;
			currentNode = nextNode;
			
			count++;	
		}
		if (m==1) {
			return result;
		}
		return head;
    }
}