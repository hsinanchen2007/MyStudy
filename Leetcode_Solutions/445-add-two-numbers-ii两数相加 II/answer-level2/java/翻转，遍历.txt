### 解题思路
参考题号2，翻转过后就跟第二题一样了，记得结果也要翻转。

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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode a = reverseNode(l1);
        ListNode b = reverseNode(l2);
        return addTwoNumbersTemp(a, b);
    }
    private ListNode addTwoNumbersTemp(ListNode a, ListNode b) {
        ListNode dummyHead = new ListNode(-1);
        ListNode cur = dummyHead;
        int temp=0;
        while (a != null || b != null) {
            int x = (a == null) ? 0 : a.val;
            int y = (b == null) ? 0 : b.val;
            int sum = x+y+temp;
            cur.next = new ListNode(sum%10);
            cur = cur.next;
            temp = sum/10;
            if (a != null) {
                a = a.next;
            }
            if (b != null) {
                b = b.next;
            }
        }
        if (temp > 0) {
            cur.next = new ListNode(temp);
        }
        return reverseNode(dummyHead.next);
    }

    private ListNode reverseNode(ListNode root) {
        if (root == null || root.next == null) {
            return root;
        }
        ListNode pre = reverseNode(root.next);
        root.next.next = root;
        root.next = null;
        return pre;
    }
}
```