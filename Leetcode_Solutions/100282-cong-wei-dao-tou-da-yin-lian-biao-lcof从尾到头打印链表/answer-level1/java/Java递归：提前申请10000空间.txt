提前申请题目所给的最大空间10000，防止用List出现扩容影响性能。

思路：递归到最后一个结点时逐个放入数组[0...n]，n为链表长度，最后裁剪数组取前n个数。
```java
class Solution {
	public static int[] reversePrint(ListNode head) {
		int[] ans = new int[10000];//申请最大空间
		int index = recursion(head, ans, 0);
		return Arrays.copyOf(ans, index);
	}

	private static int recursion(ListNode head, int[] ans, int index) {
		if (head == null) {
			return 0;
		}
		index = recursion(head.next, ans, index);
		ans[index++] = head.val;
		return index;
	}
}
```
