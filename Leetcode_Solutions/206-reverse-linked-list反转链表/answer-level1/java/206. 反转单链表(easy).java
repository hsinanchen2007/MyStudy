### 解题思路
1. 双指针迭代
	a) 申请previous，current和temp三个节点。其中，previous指向null。
	b) 首先记录current节点的下一个节点，保存于temp。
	c) 将current.next指向previous指向的节点。
	d) 将previous和current同时向后移向下一个位置。
	e) 重复操作，直至current为null(表明链表遍历结束)。
2. 递归(画图来理解)
### 代码
//双指针迭代
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
		//申请节点，temp和 current，previous指向null
		ListNode previous = null;
		ListNode current = head;
		ListNode temp = null;
		while(current != null) {
			//记录当前节点的下一个节点
			temp = current.next;
			//然后将当前节点指向previous
			current.next = previous;
			//previous和current节点都前进一位
			previous = current;
			current = temp;
		}
		return previous;
	}
}

```

### 代码
//迭代
```java
class Solution {
	public ListNode reverseList(ListNode head) {
		//递归终止条件是当前为空，或者下一个节点为空
		if(head==null || head.next==null) {
			return head;
		}
		//这里的cur就是最后一个节点
		ListNode cur = reverseList(head.next);
		//这里请配合动画演示理解
		//如果链表是 1->2->3->4->5，那么此时的cur就是5
		//而head是4，head的下一个是5，下下一个是空
		//所以head.next.next 就是5->4
		head.next.next = head;
		//防止链表循环，需要将head.next设置为空
		head.next = null;
		//每层递归函数都返回cur，也就是最后一个节点
		return cur;
	}
}

```

