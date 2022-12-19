### 解题思路
此处撰写解题思路
我的思路:
    先统计奇数和偶数的个数
    既然奇数再前面而偶数再后面的，而且不用排序的话！
我用了链表的头插法，先将偶数插入到新的链表中，然后再插入奇数到链表中，
这样的效果就是奇数再前，偶数在后的操作！
    再这期间运用了两个栈，最后返回新的链表即可;ok;
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
        int len=1;
        Stack<Integer> s1=new Stack<Integer>();
        Stack<Integer> s2=new Stack<Integer>();
        int ji=0;
        int ou=0;
        ListNode t1=head;
        ListNode t2=new ListNode(0);
        while(t1!=null){
            if(len%2==1){
                s1.push(t1.val);
                ji++;
            }else{
                s2.push(t1.val);
                ou++;
            }
            len++;
            t1=t1.next;
        }
        for(int i=0;i<ou;i++){
            if(t2!=null){
                ListNode a=new ListNode(s2.pop());
                a.next=t2.next;
                t2.next=a;
            }
        }
        for(int i=0;i<ji;i++){
            if(t2!=null){
                ListNode a=new ListNode(s1.pop());
                a.next=t2.next;
                t2.next=a;
            }
        }
        return t2.next;

    }
}
```