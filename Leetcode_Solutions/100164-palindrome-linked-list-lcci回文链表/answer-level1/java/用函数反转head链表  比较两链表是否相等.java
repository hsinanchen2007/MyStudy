### 解题思路
此处撰写解题思路

### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
  
	    //反转链表，返回一个新的链表
	 public ListNode copyHead(ListNode node) { 
		 ListNode next = null;
		  ListNode newHead = null;
		    while(node!=null) {
			ListNode n = new ListNode(node.val);
			n.next = newHead;
			newHead = n;
			
			node = node.next;
		}
		   return newHead;
	   }
	 
	 
	 public  boolean isPalindrome(ListNode head) {
		
		 //用函数反转并copy链表， 这个函数里的head并没有发生改变  
		 ListNode newHead =  copyHead(head);
		 
		 return isEqual(newHead, head);
	    
		
	}
	 
	   //判断两链表是否相等
	  public boolean isEqual(ListNode l1,ListNode l2) {
		while(l1!=null&&l2!=null) {
			if(l1.val!=l2.val) {
				 return false;
			}
			
				l1 = l1.next;
				l2 = l2.next;
		}
		 
		return true;
	 }

}
```