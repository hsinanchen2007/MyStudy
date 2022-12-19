### 解题思路
题目中说明了两个 **非空 **的链表用来表示两个**非负**的整数。其中，它们各自的位数是按照 **逆序** 的方式存储的，并且它们的每个节点只能存储 一位 数字。所以数值遇到长度不一时，只需要在短的链表后面添加0即可，这样避免了麻烦；剩下的就是要注意，单链表的虚拟头结点，用来返回链表头；

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
        //头结点 保存链表位置
        ListNode dummyHead = new ListNode(0);
        ListNode result = dummyHead;
        int carry = 0;
        while (l1 != null || l2 != null) {
            int add = carry;
            if (l1 != null) {
                add += l1.val;
                l1 = l1.next;
            }
            if (l2 != null) {
                add += l2.val;
                l2 = l2.next;
            }
            carry = add / 10;
            result.next = new ListNode(add % 10);
            result = result.next;
        }
        if (carry > 0) {
            result.next = new ListNode(carry);
        }
        return dummyHead.next;
    }
}
```