### 解题思路
不反转的话，使用双栈就OK了

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
        Stack<Integer> a = new Stack<>();
        Stack<Integer> b = new Stack<>();
        while (l1 != null) {
            a.push(l1.val);
            l1 = l1.next;
        }
        while (l2 != null) {
            b.push(l2.val);
            l2 = l2.next;
        }
        ListNode dummyHead = null;
        int temp=0;
        while (!a.isEmpty() || !b.isEmpty()) {
            int x = (a.isEmpty()) ? 0 : a.pop();
            int y = (b.isEmpty()) ? 0 : b.pop();
            int sum = x+y+temp;
            ListNode cur = new ListNode(sum%10);
            cur.next = dummyHead;
            dummyHead = cur;
            temp = sum/10;
        }
        if (temp > 0) {
            ListNode cur = new ListNode(temp);
            cur.next = dummyHead;
            dummyHead = cur;
        }
        return dummyHead;
    }
}
```