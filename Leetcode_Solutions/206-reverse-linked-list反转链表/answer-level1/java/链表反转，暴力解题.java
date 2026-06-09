### 解题思路
设置三个节点，前继节点：pre;当前节点：cur;后继节点:next。
从头结点开始，一个节点一个节点开始反转。       
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
        if(head==null||head.next==null)  return head;//链表为空或者只有一个节点直接返回
        ListNode pre=null,cur=head,next=null;
        while(cur!=null)
        {
            next=cur.next;//每次反转前，用next节点保存 
            cur.next=pre;//开始反转，用当前节点cur->前继节点pre
            pre=cur;//将前继节点往后移动
            cur=next;//将当前节点往后移动
        }
        return pre;//循环结束后，pre值为cur，cur值为null，所以要返回pre
    }
}
```