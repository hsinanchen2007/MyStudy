环形链表II--->[三种方法解环形链表II](https://leetcode-cn.com/problems/linked-list-cycle-ii/solution/huan-xing-lian-biao-ii-by-leetcode/)

### 141. 环形链表 Easy
> Two Pointer: Slow Fast Pointer
>- O(1) sapce: 用快慢指针。一个跑.next, 一个跑.next.next。 总有一次，fast会因为cycle而追上slow。
>- 那个时候其实slow.val = fast.val.


```
/**
 * 141. 环形链表 Easy
 *
 * @param head
 * @return
 */
public boolean hasCycle(ListNode head) {
    if (head == null || head.next == null) {
        return false;
    }
    ListNode slow = head;
    ListNode fast = head.next;
    while (fast.next != null && fast.next.next != null) {
        if (slow == fast) {
            return true;
        }
        slow= slow.next;
        fast =fast.next.next;
    }
    return slow == fast;
}
```
