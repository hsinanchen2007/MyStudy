### 解题思路
前提这是单链表，去找middle值，此时
1. 要么采用时间+空间互换的方式，去遍历整个链表，根据结点的数量，去选中间的节点
2. 要么采用双指针的方法，设置两个指针，快指针的速度是慢指针的2倍，这样快指针到尾的时候，慢指针刚好到中间的位置。

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
    public ListNode middleNode(ListNode head) {
        ListNode p = head, q = head;
        while(q!=null && q.next!=null){
            q = q.next.next;
            p = p.next;
        }
        return p;
    }
}
```