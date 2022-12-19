执行用时 : 2 ms, 在Merge Two Sorted Lists的Java提交中击败了97.88% 的用户
内存消耗 : 35.1 MB, 在Merge Two Sorted Lists的Java提交中击败了91.98% 的用户

首先找到开头val值最小的链表，并以此作为整链，将另一条链表依次插入到最小链表中，其中链表坐标慢慢往后移。

```
class Solution {
	public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if(l1 == null || l2 == null){    //排除空
            if(l1 == null){
                return l2;
            }
            return l1;
        }
		if (l1.val < l2.val) {    //找到最小链表
			ListNode tmp = l1;
			l1 = l2;
			l2 = tmp;
		}
		ListNode listNode = l2;
		while (true) {
			if (l1.val >= l2.val && (l2.next == null || l1.val <= l2.next.val)) {    //找到合适的位置
				ListNode posNode = l1.next;    //记录l1断开的位置
				l1.next = l2.next;                       //连接
				l2.next = l1;
				l2 = l2.next;
				if (posNode == null) {
					break;
				}
				l1 = posNode;
				continue;
			}
			l2 = l2.next;

		}
		return listNode;
	}
}
```