### 解题思路
快慢双指针解法, 多用一个int计数，也可以在计数环有多大时开始从头移动一个指针，就可以省略计数的int.

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
        //用快慢指针，如果有环，快慢两个指针终会在环内的某一个节点上相遇，
        //从相遇开始，开始计数，如果环内有 n 个节点，慢指针每走 i 步，快指针走 2 i 步，
        //所以 快慢指针的下一次相遇，还是在这个节点，慢指针刚好走了环的一圈，快指针走了两圈
        //这样就可以知道环有多大
        ListNode fast = head, slow = head;
        int count = 0;
        //第一个循环，让快慢指针在环内相遇
        while(fast != null) {
            slow = slow.next;
            if(fast.next != null) fast = fast.next.next;
            else return null;
            if(fast == slow) break;
        }
        if(fast == null) return null;
        //第二个循环，得到环的大小
        do{
            count++;
            slow = slow.next;
            fast = fast.next.next;
        }while(fast != slow);
        //第三个循环，慢指针指向头，快指针指向头后一圈的位置
        slow = head;
        fast = head;
        while(count != 0){
            fast = fast.next;
            count--;
        }
        //第四个循环，快慢指针同时后移一步，直到在环的起点相遇
        while(slow != fast){
            slow = slow.next;
            fast = fast.next;
        }
        return slow;
    }
}
```