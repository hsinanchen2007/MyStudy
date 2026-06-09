### 解题思路
此处撰写解题思路
看了很多代码都是添加了头结点，因为这样要删除的是头结点就比较容易；但可以这样
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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode first=head;
		ListNode sec=head;
        boolean flag=false;
		for (int i=1; i<=n+1; i++) {
            if(first==null){//此处可以判断要删除头结点
                head=head.next;
                sec=head;
                flag=true;
                if(sec==null){
                    return null;
                }
                continue;
            }
			first=first.next;
		}
        if(flag){
            return head;
        }
        
		while(first!=null){
			first=first.next;
			sec=sec.next;
		}
		if(sec==head){
			head.next=head.next.next;
		}else{
			sec.next=sec.next.next;
		}
		return head;
    }
}
```