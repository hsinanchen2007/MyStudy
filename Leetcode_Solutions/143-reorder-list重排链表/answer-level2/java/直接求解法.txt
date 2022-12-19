非递归解法，思路如下：
- 首先遍历一遍链表，获取链表长度len
- 根据长度len将链表分为前半部分和后半部分，其中前半部分`preLen = len % 2 == 0 ? len / 2 : len / 2 + 1`,这个很好理解，当链表长度为奇数时，前半部分比后半部分大1；
- 将后半部分进行链表反转
- 将前后半部分两个链表进行合并
总体复杂度为O(N)

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
        if(head == null) return;
        int i = 0;
        ListNode node = head;
        while(node != null) {
            node = node.next;
            i++;
        }
        int preLen = i % 2 == 0 ? i / 2 : i / 2 + 1;
        node = head;
        ListNode pre = node;
        while(preLen > 0) {
            pre = node;
            node = node.next;
            preLen--;
        }
        // 将链表冲pre和node这里分开
        pre.next = null;
        node = reverseList(node);
        // 依次将前n/2链表和后n/2链表连接起来
        ListNode preH = head;
        i = 1;
        ListNode next;
        while(preH != null || node != null) {
            //前n/2
            if(i % 2 == 1) {
                next = preH.next;
                preH.next = node;
                preH = next;
            } else {
            // 后n/2
                next = node.next;
                node.next = preH;
                node = next;
            }
            i++;
        }
    }
    // 把链表反转
    public ListNode reverseList(ListNode head) {
        if(head == null) return null;

        ListNode pre = null;
        ListNode cur = head;
        while(cur != null) {
            ListNode next = cur.next;
            if(next == null) {
                cur.next = pre;
                break;
            }
            cur.next = pre;
            pre = cur;
            cur = next;
        }
        return cur;
    }
}
```