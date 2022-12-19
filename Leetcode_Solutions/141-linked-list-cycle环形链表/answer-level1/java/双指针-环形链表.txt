最开始没理解题意（捂脸），后来才明白，传入的参数是一个链表，查看链表中是否有环的存在。
采用双指针的方法，一个指针快，一个指针慢，如果有环则快的指针一定能够再一次追上慢指针。
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
    public boolean hasCycle(ListNode head) {
        if(head == null)
            return false;
        ListNode l1 = head, l2 = head.next;
        while(l1 != null && l2 != null && l2.next != null){
            if(l1 == l2)
                return true;
            l1 = l1.next;
            l2 = l2.next.next;
        }
        return false;
    }
}
```