### 解题思路
**找到m节点和n节点后反转，然后两边连接起来**

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
    public ListNode reverseBetween(ListNode head, int m, int n) {
      	if (head == null || m >= n)
			return head;
		ListNode pre = new ListNode(0);
		pre.next = head;
		//遍历指针
		ListNode cur = pre;
		//第m个节点
		ListNode mNode=null; 
		//第n个节点
		ListNode nNode = null;
		//m节点的父节点
		ListNode leftPart = null;
		//n节点的next节点
		ListNode rightPart=null;
		//从pre开始走n步就是n节点，走m步是m节点，走m-1步是m节点的父节点
		for (int i = 0; i < n; i++) {
			if (i == m - 1)
				leftPart = cur;
			cur = cur.next;
			nNode = cur;
		}
		rightPart = nNode.next;
		mNode = leftPart.next;

		//对m-n链表进行反转
		//front是迭代节点中的要指向的next，初始为rightPart
		ListNode front = rightPart;
		//从mNode开始迭代
		cur = mNode;
		//迭代次数
		int k = n - m + 1;
		while (k > 0) {
			//当前迭代节点的next节点
			ListNode tmp = cur.next;
			//让当前节点指向当前next
			cur.next = front;
			//更新next节点
			front = cur;
			//更新迭代节点
			cur = tmp;
			//减少迭代次数
			k--;
		}
		//front就是m-n链表反转后的第一个节点，让前面的连接它
		leftPart.next = front;
		return pre.next;
    }
}
```