### 解题思路
龟兔赛跑

### 代码

```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode detectCycle(ListNode head) {
        //返回环的节点
        if (head == null || head.next == null) {
            return null;
        }

        //先判断是否有环
        ListNode fast = head;
        ListNode slow = head;

        ListNode point = null;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
            //相遇点
            if (fast == slow) {
                point = fast;
                break;
            }
        }

        //没找到环
        if (point == null) {
            return null;
        }

        //设置一个指针从头开始跑
        ListNode tailHead = head;

        if (fast == tailHead) {
            return fast;
        }

        //再次开展龟兔赛跑
        while (tailHead != fast) {
            tailHead = tailHead.next;
            fast     = fast.next;
            if (tailHead == fast) {
                return tailHead;
            }
        }
        
        return null;
    }
}
```