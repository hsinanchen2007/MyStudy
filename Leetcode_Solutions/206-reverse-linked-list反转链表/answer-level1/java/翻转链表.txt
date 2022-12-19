### 解题思路
用简单的迭代的思想去实现，要翻转一个单项链表，需要把相邻两个节点的next指向反过来，所以需要两个指针记录相邻两个节点的位置，然后一直想前迭代，直至链表最后，即新链表最前。

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
    public ListNode reverseList(ListNode head) {
        ListNode cur=head;
        ListNode pre=null;
        while(cur!=null){
            ListNode tmp=cur.next;
            cur.next=pre;
            pre=cur;
            cur=tmp;
        }
        return pre;
    }
}
```