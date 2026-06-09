### 解题思路
起初设置哨兵节点时没有对哨兵节点val值做初始化
导致其val值为默认的0 测试[0,0,0,0] 未通过
初始化sentinel对象时传入 负数参数 可解决该问题

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

        ListNode sentinel = new ListNode(-1000);
		sentinel.next = head;
		
		ListNode prevNode = sentinel;
		ListNode nexNode = sentinel.next;
		
		while(nexNode!=null) {
			if(nexNode.val == prevNode.val) {
				prevNode.next = nexNode.next;
			}else {
				prevNode = nexNode;
			}
			nexNode = nexNode.next;
			
		}
		
		return sentinel.next;
    }
}
```
```递归
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

        //递归出口判断
		if(head == null || head.next == null ) {
			return head;
		}
		//如果当前节点与下一节点val等 丢弃当前节点 直接返回处理后的next节点
		if(head.val == head.next.val) {
			return deleteDuplicates(head.next);
		}
		// 否则继续处理当前节点的next
		else {
			head.next = deleteDuplicates(head.next);
		}
		return head;
		
    }
}
```
重点在于
如果当前节点val与下一节点val等 
那么便丢弃当前节点 直接返回处理后的next