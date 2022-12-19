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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int pre = 0;

        ListNode l1Next = l1;
        ListNode l2Next = l2;
        ListNode l3 = null;
        ListNode l3Next = null;
        while(l1Next != null || l2Next != null || pre > 0){
            int val1 = l1Next == null ? 0 : l1Next.val;
            int val2 = l2Next == null ? 0 : l2Next.val;

            int value = val1 + val2 + pre;
            int num = value % 10; 
            pre = value >= 10 ? 1 : 0;

            if(l3 == null){
                l3 = new ListNode(num);
                l3Next = l3;
            } else {
                l3Next = l3Next.next = new ListNode(num);
            }

            l1Next = l1Next == null ? null : l1Next.next;
            l2Next = l2Next == null ? null : l2Next.next;
        }

        return l3;
    }
}
```