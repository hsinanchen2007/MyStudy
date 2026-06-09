使用双指针
slow指针走一步，fast指针走两步，注意链表中节点是奇数的情况

### 代码

```java
class Solution {
    public ListNode middleNode(ListNode head) {
        // 虚拟头结点
        ListNode dummyHead = new ListNode(0);
        dummyHead.next = head;
        // 慢指针
        ListNode slow = dummyHead;
        // 快指针
        ListNode fast = dummyHead;
        while(fast.next != null){
            fast = fast.next;
            // fast.next == null, 表示head中节点的个数为奇数
            // 可以终止循环
            if(fast.next != null){
                fast = fast.next;
                slow = slow.next;
            }
        }
        // 返回slow.next
        // {1,2,3,4} 结束循环的时候：slow指向2，fast指向4
        // {1,2,3,4,5} 结束循环是，slow指向2，fast指向5
        return slow.next;

    }
}
```