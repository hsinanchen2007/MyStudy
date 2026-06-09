### 解题思路
快慢（先后）指针，比如先指针比后指针先了3步，那么先指针到边界时，后指针就是想要的那个倒数第3个数

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
    public ListNode getKthFromEnd(ListNode head, int k) {

        ListNode p = head;
        ListNode q = head;

        while(k != 1){
            p = p.next;
            k--;
        }

        while(p.next != null){
            p = p.next;
            q = q.next;
        }

        return q;
    }
}
```