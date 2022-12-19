### 解题思路
直接反转链表比较简单，不管是用时还是内存都击败了100%的用户
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
    public int[] reversePrint(ListNode head) {
        if(null==head) {
			return new int[] {};
		}
		if(null==head.next) {
			return new int[] {head.val};
		}
		ListNode pre=null;
		ListNode pcur=head;
		ListNode next;
		int count=0;
		while(pcur!=null) {
			count++;
			if(pcur.next==null) {
				pcur.next=pre;
				break;
			}
			next=pcur.next;
			pcur.next=pre;
			pre=pcur;
			pcur=next;
		}
		head=pcur;
		ListNode temp=head;
		int[] intlist=new int[count];
		count=0;
		while(temp!=null) {
			intlist[count++]=temp.val;
			temp=temp.next;
		}
		return intlist;
    }
}
```
定义了三个指针变量，一个指向前一个节点，一个指向当前节点，一个用于保存当前节点的下一个节点，依次把当前节点的next指向前一个节点即可。