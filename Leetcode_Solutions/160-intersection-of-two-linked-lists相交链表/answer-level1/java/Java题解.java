### 解题思路
先都遍历一边，然后拿到两个链表的尾节点和长度 p1,p2, len1,len2
比较一下p1 p2 是否相等 是的话再看len1-len2 ，长的那个条就先走两者的差值，然后再一起走，直到遇到第一个相等的节点为止
### 代码

```java
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        ListNode p1= headA,p2=headB;
        int len1=1,len2=1;
        while(p1!=null&&p1.next!=null){
            p1=p1.next;
            len1++;
        }
        while(p2!=null&&p2.next!=null){
            p2=p2.next;
            len2++;
        }
        if(p1!=p2){
            return null;
        }
        p1=headA;
        p2=headB;
        int a;
        if(len1>len2){
            a=len1-len2;
            while(a!=0){
            p1=p1.next;
            a--;
        }
        }else{
            a=len2-len1;
            while(a!=0){
            p2=p2.next;
            a--;
        }
        }
        while(p1!=p2){
            p1=p1.next;
            p2=p2.next;
        }
       return p1;
    }
}
```