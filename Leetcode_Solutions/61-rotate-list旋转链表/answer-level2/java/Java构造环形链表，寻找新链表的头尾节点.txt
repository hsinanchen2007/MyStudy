- 完全遍历到尾部，记录链表长度
- 构造环形链表(尾节点指向头节点)
- 计算新尾节点相对偏移旧头节点多远
- 从头遍历偏移量个单位长度，找到新尾节点，新尾节点的next就是新head，截断头和尾的连接
```
class Solution {
    public ListNode rotateRight(ListNode head, int k) {
		if (head == null || head.next == null || k == 0) {
			return head;
		}
		ListNode dummy = head;
		int len = 0;
		// 从头到尾遍历链表并记录链表长度len
		while (head.next != null) {
			len++;
			head = head.next;
		}
		len++;

		// 计算需要移动多少位，主要解决k大于len的情况。
		//另外的else可以不需要，为了明显贴出来
		if (k > len) {
			// 当k大于链表长度时，先对k%len，得到尾节点距离开始节点多少个单位长度
			len = len - k % len - 1;
		} else if (k==len) {
			// 移动位数为0时直接返回原链表
			return dummy;
		}else {
			// 当k小于链表长度len时，直接移动len-k-1位
			len = len - k - 1;
		}

		//构造环形链表，即尾部指向头部
		head.next = dummy;
		head = dummy;
		//通过len寻找新链表的尾部
		for (int i = 0; i < len; i++) {
			head = head.next;
		}

		//新链表尾部的next就是head
		dummy = head.next;
		//断开环形链表，使其形成单向链表
		head.next = null;
		//返回新链表的头部
		return dummy;	
    }
}
```
