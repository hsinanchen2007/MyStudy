### 解题思路
1. 快指针先走n步
2. 快慢指针再同时走
3. 快指针到达最后时候，慢指针的位置就是倒数第n
4. 删除当前节点用 node.next = node.next.next;
5. 由于要返回当前节点的头节点，所以需要新链表记录修改后的节点

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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode node = new ListNode(0);
        node.next = head;
        ListNode fast = node;
        //快指针先走n步
        for (int i = 0; i <= n; i++){
            fast = fast.next;
        }
        ListNode slow = node;
        while (true){ //量指针同时走
            if (fast == null){ //如果快指针为空，那么慢指针的位置就是倒数第n个
                slow.next = slow.next.next;
                 //将倒数第n个的节点指向下一个节点
                return node.next;
            }
            slow = slow.next;
            fast = fast.next;
        }
    }
}
```