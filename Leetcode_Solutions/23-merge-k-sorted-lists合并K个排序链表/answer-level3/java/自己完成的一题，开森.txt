### 解题思路
暴力求解，思路简单清晰

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
    public ListNode mergeKLists(ListNode[] lists) {
        int len = 0;
		for(int i = 0;i < lists.length;i ++) {
			ListNode p = lists[i]; //每一个链表的首元结点
			while(p != null) {
				len ++;
				p = p.next;
			}
		}
		int[] arr = new int[len];
		int cur = 0;
		for(int i = 0;i < lists.length;i ++) {
			ListNode p = lists[i]; //每一个链表的首元结点
			while(p != null) {
				arr[cur++] = p.val;
				p = p.next;
			}
		}
		
		Arrays.sort(arr);
		ListNode head = new ListNode(-1);
        ListNode dummy = head;
		for (int i = 0; i < arr.length; i++) {
			ListNode q = new ListNode(arr[i]);
			head.next = q;
			head = q;
		}
		return dummy.next;
    }
}
```
![image.png](https://pic.leetcode-cn.com/8074df05d5ab34d2b6819f499a6103a9567fbd905e5db8c221066d86a19be585-image.png)
