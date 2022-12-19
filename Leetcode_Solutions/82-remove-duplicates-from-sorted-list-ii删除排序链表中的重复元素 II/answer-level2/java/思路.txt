### 解题思路
此处撰写解题思路
我的思路：
    先用排序算法，将重复的元素替换成-1000000，然后再创建一个新的链表
存放的就是这些不等于-1000000的值即可！
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
        ListNode temp1=head;
        boolean flag=false;
        while(temp!=null){
            ListNode cur=temp.next;
            while(cur!=null){
                if(temp.val == cur.val){
                    flag=true;
                    cur.val=-1000000;
                }
                    cur=cur.next;
            }
        
            if(flag){
                temp.val=-1000000;
            }
            flag=false;
            temp=temp.next;
        }
        ListNode xx=new ListNode(0);
        ListNode add=xx;
        ListNode next=null;

        while(head!=null){
            next=head.next;
            if(head.val!=-1000000){
                head.next=add.next;
                add.next=head;
                add=add.next;
            }
            head=next;
        }

        return xx.next;
    }
}
```