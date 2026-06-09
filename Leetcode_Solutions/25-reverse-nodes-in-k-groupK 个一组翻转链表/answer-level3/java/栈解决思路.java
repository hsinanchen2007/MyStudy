### 解题思路
1.当前start为需要入栈的对象。当退出循环时，当前start为下一次循环的开头。当start为空的是直接return。
2.stack.pup 存储给inListNode.next
3.inLIstNode.next=start 把链表重新连起来
![无标题.png](https://pic.leetcode-cn.com/65c810bd8dcc92e800bc4dd4fd2a68759ab7a2a916c026c3d894c13b3218873f-%E6%97%A0%E6%A0%87%E9%A2%98.png)


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
    public ListNode reverseKGroup(ListNode head, int k) {
        		Stack<ListNode> stack = new Stack<ListNode>();
		ListNode hh = new ListNode(0);
		ListNode reListNode = hh;
		ListNode inListNode = hh;
		ListNode start = head;
		while (start != null) {
			for (int i = 0; i < k; i++) {
				if (start != null) {
					stack.push(start);
					start = start.next;
				}else {
					return reListNode.next;
				}
			}
			for (int i = 0; i < k; i++) {
				inListNode.next = stack.pop();
				inListNode = inListNode.next;
				
			}
			inListNode.next = start;
			
		}
		return reListNode.next;
    }
}
```