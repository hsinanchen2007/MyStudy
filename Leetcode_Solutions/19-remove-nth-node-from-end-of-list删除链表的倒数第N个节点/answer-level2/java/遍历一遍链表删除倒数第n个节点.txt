### 解题思路
c删除链表的第n个节点是很常见的操作，直接遍历删除即可。对于倒数的情况我们也需要转化为正数着来做。

可以每次遍历n个节点，然后统计遍历节点的个数，如果节点数目小于n,则需要从上一次的n此遍历中补上缺少的节点数目。
比如，遍历了k个n次遍历，最后遍历到链表尾端统计的节点数为m次，则，需要从上一次的n次遍历中获取到n-m个节点。
也就是从k-1次遍历开始的位置走m步即到达我们要删除的节点的前驱节点处。接下来就是正常的删除链表节点操作。

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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode current = head , last = current, start = current;
        int count = 0;
        while(current != null){
            if(count == n){
                count =0;
                if(last != start)
                    last = start;
                start = current;
            }
            current = current.next;
            count++;
        }
        if(last == start)
            return head.next;
        while(--count > 0){
            last = last.next;
        }
        last.next =last.next.next;
        return  head;
    }
}
```