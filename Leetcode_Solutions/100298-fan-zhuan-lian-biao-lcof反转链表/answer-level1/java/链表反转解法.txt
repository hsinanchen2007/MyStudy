### 解题思路
**图文搭配讲解链表反转，看不懂你来打我。面试高频题，写不出来就滚蛋**
[https://zhuanlan.zhihu.com/p/102908327]()
复制了在浏览器直接访问

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
        if(head==null||head.next==null){
            return head;
        }
        ListNode p1=head;
        ListNode p2=head.next;
        ListNode p3=null;

        while(p2!=null){
            p3=p2.next;
            p2.next=p1;
            p1=p2;
            p2=p3;
        }
        head.next=null;
        head=p1;
        return head;
    }
}
```