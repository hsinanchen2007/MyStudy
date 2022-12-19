### 解题思路
整体画个图，起始挺简单的，核心算法也挺好找的，不解释了。

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
    public ListNode oddEvenList(ListNode head) {
        if(head == null || head.next == null || head.next.next == null)
            return head;

        ListNode odd = head;
        ListNode even = head.next;
        ListNode newhead = even;
        ListNode tail = head.next.next;
        odd.next = null;
        even.next = null;

        for(int i = 1; tail != null; i++){
            if(i % 2 == 1){
                odd.next = tail;
                tail = tail.next;
                odd = odd.next;
                odd.next = null;
            }else{
                even.next = tail;
                tail = tail.next;
                even = even.next;
                even.next = null;
            }
        }
        odd.next = newhead;
        return head;
    }
}
```