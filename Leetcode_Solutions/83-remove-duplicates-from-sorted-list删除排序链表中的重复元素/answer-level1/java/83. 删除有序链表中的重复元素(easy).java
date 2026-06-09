### 解题思路
1. 维护一个遍历有序链表的指针current。
2. 首先考虑边界问题
    a) 开头两个节点值重复没有影响，删除后面一个即可。
    b) 当指针遍历到链表结尾的时候，current或者current.next为null时，跳出循环。
    c) 返回链表头节点。
[note]如果未能清楚地考虑循环中出现的结尾边界问题时，可以考虑维护previous和current两个指针。

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
    public ListNode deleteDuplicates(ListNode head){
        ListNode current = head;
        while (current != null && current.next != null){
            if (current.next.val == current.val){
                current.next = current.next.next;
            }
            else{
                current = current.next;
            }
        }
        //链表的head地址就是链表的地址，返回head即可
        return head;
    }
}
```