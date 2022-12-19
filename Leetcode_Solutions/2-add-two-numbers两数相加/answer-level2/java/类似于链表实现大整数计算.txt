### 解题思路
1.把长的链表的数字直接接在短的联表后面
2.判断进位的情况，极端的如1+9999999的情况，需要一直进位

### 代码

```java
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
    	ListNode head1 = l1;
    	int temp = 0;
    	while (l1 != null || l2 != null) {
    		l1.val = l1.val + l2.val + temp;
    		temp = 0;
    		if (l1.val >= 10) {
				temp = 1;
				l1.val = l1.val % 10;
			}
    		if (l1.next == null) {
				l1.next = l2.next;
				while (temp != 0) {
					if (l1.next == null) {
							l1.next = new ListNode(1);
							temp = 0;
					} else {
						l1 = l1.next;
						l1.val++;
						temp = 0;
						if (l1.val > 9) {
							l1.val = l1.val % 10;
							temp = 1;
						}
					}
				}
				break;
			}
    		if (l2.next == null) {
    			while (temp != 0) {
					if (l1.next == null) {
							l1.next = new ListNode(1);
							temp = 0;
					} else {
						l1 = l1.next;
						l1.val++;
						temp = 0;
						if (l1.val > 9) {
							l1.val = l1.val % 10;
							temp = 1;
						}
					}
				}
				break;
			}
    		l1 = l1.next;
    		l2 = l2.next;
		}
    	return head1;
    }
}
```