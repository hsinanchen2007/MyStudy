### 解题思路
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
        ListNode p1 =headA,t1= headA;
        ListNode p2 =headB,t2= headB;      
        while(p1!= null&&p2!=null)//其中一个走完了，停下来，计算另一个没走完的还剩多少。第二次遍历的时候让长的那个先走计算的长度次
        {
            p1=p1.next;
            p2=p2.next;
        }
        if(p1==null)
        {
            while(p2!=null)
             {
                 t2=t2.next;
                 p2=p2.next;
             }
        } 
        if(p2==null)
        {
            while(p1!=null)
             {
                 t1=t1.next;
                 p1=p1.next;
             }
        }
        while(t1!= null&&t2!=null)
        {
            if(t1==t2)
            return t1;
            t1=t1.next;
            t2=t2.next;
        }
        return null;
    }
}
```