### 解题思路
我当时拿到这个题首先想到的就是递归实现。
看看我的代码其实并不难理解，首先判断L1,L2为空的情况，将结果链表的第一个节点初始化出来，然后就可以进入递归了（此时定义了一个节点来记录该头结点）。
递归中我是定义了一个单独的递归函数，因为要每次将结果链表传进去，需要三个参数。
递归过程并不难理解，当l1,l2均为空的时候最后返回，否则每次递归运算，通过比较大小，将结果链表的当前节点的值赋值为L1或者L2当前节点的最小值，然后再次递归。

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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode finalList;
		ListNode head;
		if (l1 != null && l2 == null) {
			finalList = new ListNode(l1.val);
			l1 = l1.next;
		} else if (l1 == null && l2 != null) {
			finalList = new ListNode(l2.val);
			l2 = l2.next;
		} else if (l1 == null && l2 == null) {
			return null;
		} else {
			if (l1.val > l2.val) {
				finalList = new ListNode(l2.val);
				l2 = l2.next;
			} else {
				finalList = new ListNode(l1.val);
				l1 = l1.next;
			}
		}
		head = finalList;
		merge(l1, l2, finalList);
		return head;
	}

	public ListNode merge(ListNode l1, ListNode l2, ListNode finalList) {
		if (l1 != null && l2 == null) {
			finalList.next = l1;
			finalList = finalList.next;
			return merge(l1.next, l2, finalList);
		} else if (l1 == null && l2 != null) {
			finalList.next = l2;
			finalList = finalList.next;
			return merge(l1, l2.next, finalList);
		} else if (l1 == null && l2 == null) {
			return finalList;
		} else {
			if (l1.val > l2.val) {
				finalList.next = l2;
				finalList = finalList.next;
				return merge(l1, l2.next, finalList);
			} else {
				finalList.next = l1;
				finalList = finalList.next;
				return merge(l1.next, l2, finalList);
			}
		}
	}
}
```