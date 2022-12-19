使用**快慢指针**，快指针fast指到末尾时，慢指针slow就是所需的结果,直接return slow;即可。

本来还预先做了以下判空，后来发现没必要。。
```
if (head == null || head.next == null) {
	return head;
}
```

```
//题解代码：快慢指针
public ListNode middleNode(ListNode head) {
	ListNode fast = head;
	ListNode slow = head;
	while (fast != null && fast.next != null) {
		fast = fast.next.next;
		slow = slow.next;
	}
	return slow;
}
```
