### 解题思路
从左到右遍历链表，以 count 记录当前 group 内节点数，当 count == k 时，先将当前 group 与链表后部分断开，将 group 内链表反转，再将此 group 与后部分连接起来并重置 count 为 1，对后续链表部分做相同操作。

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
    public ListNode reverseKGroup(ListNode head, int k) {
        if (head == null || head.next == null) {
            return head;
        }

        // left 指针记录当前 group 的开始位置，next 指针记录开始寻找下一个 group 的开始处
        ListNode curr = head, left = head, next;
        ListNode res = new ListNode(0);
        // tail 指针记录上一个 group 的结束位置
        ListNode tail = res;
        int count = 1;
        while (curr != null) {
            curr = curr.next;
            if (curr != null) {
                count++;
                if (count == k) {
                    count = 1;
                    next = curr.next;
                    // 先将当前 group 与链表后部分断开
                    curr.next = null;
                    // 翻转当前 group 内链表
                    tail.next = reverseLinkedList(left);
                    tail = left;
                    curr = next;
                    left = curr;
                }
            } else {
                break;
            }
        }
        // 接上剩余不足 k 个节点的部分
        tail.next = left;

        return res.next;
    }

    private ListNode reverseLinkedList(ListNode head) {
        if (head == null || head.next == null) {
            return head;
        }

        ListNode prev = null, curr = head, next;
        while (curr != null) {
            next = curr.next;
            curr.next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }
}
```