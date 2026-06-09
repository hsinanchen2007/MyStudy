![image.png](https://pic.leetcode-cn.com/e5923c6f0a29f37cc2310da147477b37e865751a9d68ee727e50ad4362cf94ea-image.png)

使用原链返回，使用了O(1)额外空间，当计算到两链长度不一致时补0节点，其实也可以同时修改两条链，以较长的链为返回链。
```
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = l1;
        int carry = 0;
        while (l1 != null || l2 != null) {
            l1.val += carry;
            carry = (l1.val + l2.val) / 10;
            l1.val = (l1.val + l2.val) % 10;
            if (l1.next != null || l2.next != null) {
                if (l1.next == null) {
                    l1.next = new ListNode(0);
                }
                if (l2.next == null) {
                    l2.next = new ListNode(0);
                }
            } else if (carry != 0) {
                l1.next = new ListNode(carry);
                break;
            }
            l1 = l1.next;
            l2 = l2.next;
        }
        return head;
    }
}
```
