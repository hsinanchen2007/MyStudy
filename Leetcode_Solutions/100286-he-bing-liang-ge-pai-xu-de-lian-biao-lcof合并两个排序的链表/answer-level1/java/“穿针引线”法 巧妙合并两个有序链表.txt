### 解题思路
用链表来实现合并两个有序序列，可以先创建一个头节点，再在两个链表序列中按大小顺序穿针引线，排成一条有序链表然后返回头节点的后一个节点即可。

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
        ListNode head = new ListNode(0);//作为头指针
		ListNode cur = head;//作为“穿针引线的针头”
		while(l1 != null && l2 != null) {
			if(l1.val <= l2.val) {
				cur.next = l1;
				l1 = l1.next;
			}else {
				cur.next = l2;
				l2 = l2.next;
			}
			cur = cur.next;
		}
		if(l1 != null) cur.next = l1;
		if(l2 != null) cur.next = l2;
		return head.next;//返回头节点的后一个节点
    }
}
```