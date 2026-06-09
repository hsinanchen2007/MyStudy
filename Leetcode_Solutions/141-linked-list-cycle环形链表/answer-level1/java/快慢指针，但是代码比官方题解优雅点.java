```
public boolean hasCycle(ListNode head) {
    /**
     * slow为慢指针，步长为1，fast为快指针，步长为2
     */
    ListNode slow = head;
    ListNode fast = head;
    
    while (fast!= null && fast.next != null) {
        slow = slow.next;
        fast = fast.next.next;

        /**
         * 如果有环的话，两个指针终会指向同一个节点
         */
        if(slow == fast) {
            return true;
        }
    }

    /**
     * 我们遇到空了，说明链表遍历完成
     */
    return false;
}
```
