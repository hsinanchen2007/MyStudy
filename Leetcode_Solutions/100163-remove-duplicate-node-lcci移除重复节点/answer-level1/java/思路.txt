### 解题思路
此处撰写解题思路
我的思路:
    先用排序算法将重复的节点值替换成-1100000，然后创建一个新的链表
将原有的非-1100000的值的节点赋给新的链表即可！
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
    public ListNode removeDuplicateNodes(ListNode head) {
            ListNode temp=head;
            while(temp!=null){
                ListNode cur=temp.next;
                while(cur!=null){
                    if(temp.val==cur.val){
                        cur.val=-1100000;
                    }
                    cur=cur.next;
                }
                temp=temp.next;
            }
            ListNode news=new ListNode(0);
            ListNode temp1=news;
            ListNode next=null;
            while(head!=null){
                next=head.next;
                if(head.val!=-1100000){
                   head.next=temp1.next;
                   temp1.next=head;
                   temp1=temp1.next;
                }
                head=next;
            }
            return news.next;
    }
}
```