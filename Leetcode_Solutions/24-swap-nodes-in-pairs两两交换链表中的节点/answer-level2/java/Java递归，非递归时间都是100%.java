### 解题思路
可能最近刷题有感觉了，之前觉得很难写的递归，竟然都能一下子写出来了。递归很简单啦，以1->2->3->4->null为例说明。先将1和2互换，然后将1指向递归函数即可。非递归类似的思路。其实递归和非递归有关系的，自己写几个就能感觉出来了。

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
    public ListNode swapPairs(ListNode head) {
        if(head == null || head.next == null)
            return head;
        ListNode next = head.next;
        ListNode next2 = head.next.next;
        next.next = head;
        head.next = swapPairs(next2);
        return next;
    }
}
```

```java
public ListNode swapPairs(ListNode head){
    if(head == null || head.next == null)
        return head;
    ListNode pre = new ListNode(-1);
    ListNode preHead = pre;
    pre.next = head;
    ListNode cur = head;
    while(cur != null && cur.next != null){
        ListNode next = cur.next;
        ListNode next2 = cur.next.next;
        pre.next = next;
        next.next = cur;
        pre = cur;
        pre.next = next2;
        cur = next2;
    }
    return preHead.next;
}
```