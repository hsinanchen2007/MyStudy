### 解题思路
递归相当于不停将head.next压栈。
newnode相当于是末节点,一直return回来没变过。
每次的head都往前退一个节点。

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
    public ListNode reverseList(ListNode head) {
        if(head==null||head.next==null){
            return head;
        }

        ListNode newnode = reverseList(head.next);
        head.next.next = head;
        head.next = null;
        return newnode;
    }
}
```