### 解题思路
此处撰写解题思路

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
    public void reorderList(ListNode head) {
        ListNode temp = head;
        int count = 0;
        while (temp != null) {
            count++;
            temp = temp.next;
        }

        if (count < 2) {
            return;
        }
        // 将temp 分成两段,左边大于或等于右边
        int mid = (count + 1) / 2;
        ListNode head2 = null;
         temp = head;
        while (mid > 1) {
            temp = temp.next;
            mid--;
        }
        head2 = temp.next;
        temp.next = null;
        // 将head1 翻转
        ListNode temp2 = head2;
        ListNode pre = null;
        ListNode next = null;
        while (temp2 != null) {
            next = temp2.next;
            temp2.next = pre;
            pre = temp2;
            temp2 = next;
        }
        // 重新赋值
        head2 = pre;

        temp=head;
        temp2=head2;
        ListNode next1;
        ListNode next2;
        while (temp!=null&&temp2!=null){
            next1=temp.next;
            next2=temp2.next;
            temp.next=temp2;
            temp2.next=next1;
            temp=next1;
            temp2=next2;
        }
    }
}
```