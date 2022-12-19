### 解题思路

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
    public ListNode removeNthFromEnd(ListNode head, int n){
		if(head==null||n<=0){
			return null;
		}
		ListNode headNode = head;
		ListNode pre = new ListNode(0);
        pre.next = head;
		//链表的长度
        int len = 1;  
		//因为pre在head前面，head还要走n-1
		for(int i=1;i<n;i++){
			//这里如果n大于链表的长度 直接返回null
			if(head.next!=null){
				head = head.next;
                len++;
			}else{
				return null;
			}			
		}
		
		while(head.next!=null){
			pre = pre.next;
			head = head.next;
            len++;
		}
        pre.next = pre.next.next;
		//如果n为链表的长度，那么头结点已经被删除了，需要返回头结点的下一个节点
        return n==len?headNode.next:headNode;
	}
}
```