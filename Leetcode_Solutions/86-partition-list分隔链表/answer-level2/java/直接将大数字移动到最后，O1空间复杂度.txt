思路就是
·直接将大数字移动到最后，前面就是小数字了，并不需要两个链表

·重点：
1. 先遍历一遍找出链表结尾end，并做个标签endTag
2. 从头开始遍历链表，遇到比x大的就丢到最后。（但是我的代码不能判断最后一个node>x的情况，所以就在后面加了一个if(&&)判断）
3. 水平有限o(╯□╰)o 
```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) { val = x; }
 * }
 */
class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode fake=new ListNode(99);
        fake.next=head;
        
        ListNode end=head;
        ListNode temp=head;
        if (head==null){
            return head;
        }
        //计算最后一个node
        while(end.next!=null){
            end=end.next;
        }
        ListNode endTag=end;
        ListNode headTag=fake;
        
        while(fake.next!=endTag){
            //temp=head.next.next;
            //swap,先将下一个node移动到最后，再将.next指向.next.next
            if (fake.next.val>=x){
                end.next=fake.next;
                end=end.next;
                temp=end.next;
                end.next=null;//将end断开
                fake.next=temp;  
            }else{
                fake=fake.next;
            }
        }
        if (fake.next == endTag && fake.next.val >= x) {
            end.next = fake.next;
            end = end.next;
            temp = end.next;
            end.next = null;
            fake.next = temp;
        }
        return headTag.next;
    }
}
```



