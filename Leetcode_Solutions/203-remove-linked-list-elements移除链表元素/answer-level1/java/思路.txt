### 解题思路
此处撰写解题思路
我的思路:
    首先创建一个新的链表,然后再循环参数中的链表，将不等于参数2的原元素都放入到新的链表中即可！
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
    public ListNode removeElements(ListNode head, int val) {
            
            ListNode cur=new ListNode(0);
         ListNode temp=cur;
         ListNode next=null;
         while(head!=null){
                next=head.next;
             if(head.val!=val){
              
                 head.next=temp.next;
                 temp.next=head;
                 temp=head;
             }
             head=next;
         }
         return cur.next;
    }
}
```