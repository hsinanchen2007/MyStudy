### 解题思路
此处撰写解题思路
我的思路:
    先用排序的算法将重复的值赋值给-1000000，然后创建一个新的链表
用旧的链表循环，将不等于-1000000的值赋值给新的链表即可！
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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode temp=head;

        while(temp!=null){
            ListNode cur=temp.next;
            while(cur!=null){
                if(temp.val == cur.val){
                    cur.val=-1000000;
                }
                cur=cur.next;
            }
            temp=temp.next;
        }
        ListNode xxx=new ListNode(0);
        ListNode xx=xxx;
        ListNode next=null;
        while(head!=null){
            next=head.next;
            if(head.val!=-1000000){
                head.next=xx.next;
                xx.next=head;
                xx=xx.next;
            }
            head=next;
        }
        return xxx.next;
    }
}
```