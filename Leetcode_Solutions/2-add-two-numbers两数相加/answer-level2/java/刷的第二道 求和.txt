### 解题思路
简单思路就是链表从头开始按位相加，长度不一致时候置0，
然后会有进位，所以再提炼一个方法，入参加一个进位。然后递归调用完事

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
        public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
             return addTwoNumbers2( l1, l2,0);
    }
    public ListNode addTwoNumbers2(ListNode l1, ListNode l2,int v) {
        int a=0;
        int b=0;
        ListNode a1=null;
        ListNode a2=null;
              if(l1!=null)
              {
                  a=l1.val;
                  a1=l1.next;
              }
              if(l2!=null){
                  b=l2.val;
                  a2=l2.next;
              }
         int v1=(int)Math.floor((a+b+v)/10);
        ListNode a3=new ListNode((a+b+v)%10); 
        if(a1!=null||a2!=null||v1>0) {
        a3.next=addTwoNumbers2( a1, a2,v1);
        }
        return a3;
    }
}
```