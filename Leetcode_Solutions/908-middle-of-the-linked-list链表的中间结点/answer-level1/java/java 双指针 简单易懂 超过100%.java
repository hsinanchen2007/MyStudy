### 解题思路
两个指针，一个每次走1步，一个每次走2步，当第二个指针为null时，表示走到了结尾，此时第一个指针刚好在链表中间，需要注意的是对于偶数情况，需要根据题意返回第二个中间节点

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
    public ListNode middleNode(ListNode head) {
        if(head == null) return head;

        //每次走一步
        ListNode one = head;
        //每次走两步
        ListNode two = head;
        while(two != null){
            two = two.next;
            if(two == null){
                return one;
            }
            one = one.next;
            two = two.next;
        }
        return one;
    }
}
```