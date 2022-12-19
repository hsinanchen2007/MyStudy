### 解题思路
使用n1，n2两个指针，n1每次跳两个节点，n2每次跳一个节点，n1到达链表尾部时，n2正好为中间节点

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
        ListNode n1 = head;
        ListNode n2 = head;

        while (n1 != null){
            if (n1.next == null)
                return n2;
            n1 = n1.next.next;
            n2 = n2.next;
        }
        return n2;
    }
}
```