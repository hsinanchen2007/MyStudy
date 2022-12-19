### 图解
![反转链表.gif](https://pic.leetcode-cn.com/4678e97d02c79f71e1fe55fbeefabdf70b2018b39d72dbeb98479dc6d1f4f207-%E5%8F%8D%E8%BD%AC%E9%93%BE%E8%A1%A8.gif)

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
    public ListNode reverseList(ListNode head) {
       ListNode prev,mid,curr;
		if(head==null) {
			return null;
		}
		prev=head;
		if(head.next==null) {
			return head;
		}
		mid=head.next;
		if(mid.next==null) {
			mid.next=prev;
			prev.next=null;
			return mid;
		}
		curr=mid.next;
		prev.next=null;
		while(curr.next!=null) {
			mid.next=prev;
			prev=mid;
			mid=curr;
			curr=curr.next;
		}
        mid.next=prev;
		curr.next=mid;
		return curr;
    }
}
```