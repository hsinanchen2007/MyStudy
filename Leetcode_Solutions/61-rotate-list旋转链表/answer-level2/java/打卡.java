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
    public ListNode rotateRight(ListNode head, int k) {
        //处理平凡情况
        if(head==null) return head;
        ListNode dumpy =new ListNode(0);
        dumpy.next=head;
        ListNode trail=head;
        int length=getLength(head);
        int val=k%length;
        for(int i=0;i<length-val-1;i++){
            trail=trail.next;
        }
        
        ListNode start=dumpy;
        while(trail.next!=null){
            ListNode insert=trail.next;
            trail.next=trail.next.next;
            start.next=insert;
            insert.next=head;
            start=insert;
        }
        return dumpy.next;
    }
    
    public static int getLength(ListNode head){
        int length=0;
        while(head!=null){
            head=head.next;
            length++;
        }
        return length;
    }
}
```