### 解题思路
定义一个指针指向我们原来的链表，通过遍历链表，让快指针走完链表全程，让慢指针走完链表一半，这时，慢指针所指向的位置就是我们要找的中间节点。

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
        if (head == null || head.next == null) {
            return head;
        }
        int cnt = 1;
        ListNode list = head;
        while (head.next != null) {
            head = head.next;
            cnt ++;
            if (cnt % 2 == 0){
                list = list.next;
            }
        }
        return list;
    }
}
```