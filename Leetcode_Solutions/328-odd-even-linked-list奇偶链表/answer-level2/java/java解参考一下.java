### 解题思路
此处撰写解题思路

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
    public ListNode oddEvenList(ListNode head) {
        ListNode node1,node1_;
        ListNode node2,node2_;
        ListNode node;
        if(head==null) return null;
        node1=node1_=head;
        if(head.next==null) return head;
        node2=node2_=head.next;
        if(node2.next==null) return head;
        node=node2.next;
        while(true){
            node1.next=node;
            node1=node;
            if(node.next==null) break;
            node=node.next;
            node2.next=node;
            node2=node;
            if(node.next==null) break;
            node=node.next;
        }
        node1.next=node2_;
        node2.next=null;
        return node1_;
    
    }
}
```