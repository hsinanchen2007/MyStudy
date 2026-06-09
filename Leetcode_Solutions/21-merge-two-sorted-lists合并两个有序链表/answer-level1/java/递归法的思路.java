### 解题思路
一共有2个链表，现在我们假设一条链表是0->2->6->8，另外一条链表为1->3->5->7

递归的思路是，每次比较这个链表的第一个节点

第一次比较：0 < 1
所以去掉0，然后把0指向剩下的合并链表，将剩余的2->6->8和1->3->5->7做比较

第二次比较：1 < 2
所以去掉2，然后把2指向剩下的合并链表，同时上面有0指向了合并链表，所以新的链表为0->2->剩余合并链表

按照上诉思路一直走下去
最终得到结果

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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null) {
            return l2;
        }
        
        if (l2 == null) {
            return l1;
        }
        
        if (l1.val < l2.val) {
            l1.next = mergeTwoLists(l1.next, l2);
            return l1;
        } else {
            l2.next = mergeTwoLists(l1, l2.next);
            return l2;
        }
    }
}
```