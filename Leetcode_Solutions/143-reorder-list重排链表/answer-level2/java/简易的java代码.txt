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
    public void reorderList(ListNode head){
		// 将链表中除head外的元素依次入栈，通过pop可实现从后向前遍历
		if(head == null){
			return;
		}
		Stack<ListNode> stack = new Stack<>();
		Queue<ListNode> queue = new LinkedList<>();
		ListNode p = head.next;
		int sum = 0;
		int countQ = 0;// 记录从前向后插入的结点数
		int countS = 0;// 记录从后向前插入的结点数
		while(p!=null){
			stack.push(p);
			queue.add(p);
			p = p.next;
			sum++;
		}
		// 开始重排链表
		p = head;
		while(countQ+countS<sum){
			p.next = stack.pop();
			p = p.next;
			countS++;
			if(countQ+countS<sum){
				p.next = queue.poll();
				p = p.next;
				countQ++;
			}
		}
		p.next = null;
	}
}
```

### 欢迎与我交流

![wechat.png](https://pic.leetcode-cn.com/3ff65007142ceefd2d0f6c52a1d30c7e28f07840470585bf3393fe10cd39547a-wechat.png)
