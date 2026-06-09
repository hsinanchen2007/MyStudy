### 解题思路
此处撰写解题思路
我的思路:
    首先要判断当前的位置的下一个是否为空，如果为空那就直接返回Null，不返回的话会出错的
    1. 然后用一个辅助的节点，记录当前节点的值
    1. 因为要算倒数k个的值，那么首先得这个链表的总体长度是多少，用总体的长度去减去这个K，然后
    1. 再根据k的值，循环K前面的值，将这个辅助的节点指针移动打扫K的前一个位置，循环完以后将
    1. 当前的next指向当前的next的next就可以实现删除。
上面的Next的next其实就是通过链表直接跳过要删除的数，链接到要删除的数的后面的一个位置就行了！
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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode temp=head;
        ListNode cur=head;
        ListNode c=head;
        int len=0;
        if(head.next==null){
            return null;
        }
        while(temp!=null){
            len++;
            temp=temp.next;
        }
       if(len-n==0){
           return head=c.next;
       }
       for(int i=1;i<len-n;i++){
          
           cur=cur.next;
       }
       cur.next=cur.next.next;

       return head;
    }
}
```