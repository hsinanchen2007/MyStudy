### 解题思路
此处撰写解题思路

### 代码

```java
class Solution {
	public ListNode reverseList(ListNode head) {

		ListNode pre = null;
		ListNode cur = head;
		ListNode tmp = null;
		while(cur!=null) {
			tmp = cur.next;
			cur.next = pre;
			pre = cur;
			cur = tmp;
		}
		return pre;
	}

}
```