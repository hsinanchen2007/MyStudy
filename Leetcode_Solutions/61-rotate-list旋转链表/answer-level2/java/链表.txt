### 解题思路
开始的时候进行预处理，算出链表的长度，然后讲移动次数k进行优化。k = k % len;这样可以减少很多次无意义的移动。
然后就开始递归移动。写好一次移动就可以解决len长度之内的移动了。
同时也要注意当前节点是否为null的时候。

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

    public ListNode move(ListNode node, int k){
        if(k == 0)
            return node;
        ListNode fast = node.next;
        ListNode low = node;

        while(fast.next != null){
            fast = fast.next;
            low = low.next;
        }

        low.next = null;
        fast.next = node;
        node = fast;
        k -= 1;
        node = move(node, k);
        return node;
    }

    public ListNode rotateRight(ListNode head, int k) {
        if(head == null || head.next == null)
            return head;
        int len = 0;
        ListNode tail = head;
        while(tail != null){
            len = len + 1;
            tail = tail.next;
        }
        k = k % len;

        head = move(head, k);
        return head;
    }
}
```