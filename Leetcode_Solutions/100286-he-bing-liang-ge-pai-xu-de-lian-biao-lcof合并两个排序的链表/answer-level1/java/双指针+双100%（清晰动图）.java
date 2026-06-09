
### 解题思路

![合并两个排序链表.gif](https://pic.leetcode-cn.com/091b0a27b335fa1e77fd3d4521abe3930ae659c56728a7012e26bad30443faf1-%E5%90%88%E5%B9%B6%E4%B8%A4%E4%B8%AA%E6%8E%92%E5%BA%8F%E9%93%BE%E8%A1%A8.gif)

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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1==null) {
			return l2;
		}
		if(l2==null) {
			return l1;
		}
		ListNode head= new ListNode(0);
		ListNode prev=l1,curr=l2,temp=head;
		while(prev!=null || curr!=null) {
			if(prev!=null && curr!=null) {
				if(prev.val<curr.val) {
					temp.next=prev;
					prev=prev.next;
				}else {
					temp.next=curr;
					curr=curr.next;
				}
			}else if(prev!=null) {
				temp.next=prev;
				prev=prev.next;
			}else if(curr!=null) {
				temp.next=curr;
				curr=curr.next;
			}
			temp=temp.next;
		}
		return head.next;
    }
}
```