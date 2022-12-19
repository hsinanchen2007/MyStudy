双指针(假设有环) 
设其中直链部分长度为n，圆环中节点的个数为m；注：环与直链的相交点算在环中，且环中各个节点的标记为[0, m - 1];设有两个指针fast和slow，二者皆初始化为head。fast一次走两个位置，slow每次移动一个位置，则经过n次之后，slow位于环中标记为0的位置。fast位于环中(2n - n) mod m的位置。设再经过k次循环，fast和slow可以相遇。那么有公式(k mod m) = (n + 2k) mod m  。所以有**(n + k) mod m = 0知道k和n之间的关系 **；且**相遇点位于环中标记为(k) mod m的位置**。这时两个起点分别定在head和相遇点的指针一步一步的移动，那么n次循环后，以相遇点为起点的指针的位置为(k + n) mod m = 0，而此时以head为起点的指针也到了这里，所以二次相遇的点就是环的起点    

```
public ListNode detectCycle(ListNode head) {
        if (head == null)
            return null;
        ListNode fast = head, slow = head;
        while(true) {
            if (fast.next == null || fast.next.next == null)
                return null;

            fast = fast.next.next;
            slow = slow.next;
            
            if (fast == slow) {
                fast = fast;
                slow = head;
                break;
            }
        }
        while(true) {
            if (slow == fast)
                return slow;
            slow = slow.next;
            fast = fast.next;
        }

    }
```

