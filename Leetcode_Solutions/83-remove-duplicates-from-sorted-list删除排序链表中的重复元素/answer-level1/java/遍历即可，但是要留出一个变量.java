### 解题思路
     遍历整个列表，并设置一个last变量，存储上一个并入链表的数值，如果遍历经过的节点数值与last变量相等，则直接向下一位，否则，并入新的节点值，并刷新last的数值。

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
    public ListNode deleteDuplicates(ListNode head) {
          if(head==null)
	    	 return null;
         ListNode ans=new ListNode(0);
	     ListNode p=new ListNode(0);
	     p.val=head.val;
	     ans=p; 
	     int last=p.val;
	     ListNode ite=head;
	    ite=ite.next;
	     while(ite!=null)
	     {
	    	 if(ite.val!=last)
	    	 {
	    		 ListNode tmp=new ListNode(ite.val);
	    		 p.next=tmp;
	    		 p=p.next;
	    		 last=ite.val;
	    		 ite=ite.next;
	    	 }
	    	 else
	    	 {
	    		ite=ite.next;
	    	 }
	    	 
	     }
	     return ans;
	     
    }
}
```