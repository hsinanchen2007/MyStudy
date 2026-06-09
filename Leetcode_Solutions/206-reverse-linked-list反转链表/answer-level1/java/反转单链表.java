### 解题思路
核心： 把链表next指针 指向上一个节点 所以要有一个前置节点prev
实现： curr.next.next= prev
循环： 我需要遍历整个链表，且要先保存当前处理节点的next
提示： null指针可以考虑作为一个空节点
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

if(head==null){return head;}
     // 把链表next指针 指向上一个节点 所以要有一个前置节点prev
     //  curr.next.next= prev
     // 我需要遍历整个链表，且要先保存当前处理节点的next
     // null指针可以考虑作为一个空节点

     
ListNode preNode=null;
ListNode currNode=head;

while(currNode!=null){
   ListNode nextNode=currNode.next;
   currNode.next=preNode;
   preNode=currNode;
   currNode=nextNode;
}
        return preNode;
    }
}
```