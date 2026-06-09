
```java
class Solution {
    public ListNode insertionSortList(ListNode head) {
        if( head == null ){
			return head;
		}
		
        // 创建哨兵节点
		ListNode dummy = new ListNode(0);
        // 当前需要插入的节点 
		ListNode cur = head; 
        // 将 cur 插入到 pre 节点和 pre.next 节点之间
		ListNode pre = dummy; 
        // 下一个需要插入的节点
		ListNode next = null; 
		
		while( cur != null ){
            // 先记住下一个需要插入的节点
			next = cur.next;
			// 找到当前节点需要插入的位置
			while( pre.next != null && pre.next.val < cur.val ){
				pre = pre.next;
			}
			// 将当前的节点插入到 pre 到 pre.next 之间
			cur.next = pre.next;
			pre.next = cur;

            // 将 pre 重新指向链表的第一个节点
			pre = dummy;
            // 迭代下一个节点
			cur = next;
		}
		
		return dummy.next;
    }
}
```