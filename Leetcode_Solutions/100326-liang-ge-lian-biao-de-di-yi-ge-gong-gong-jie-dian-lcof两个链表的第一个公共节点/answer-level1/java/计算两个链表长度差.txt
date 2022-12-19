### 解题思路
1.计算两个链表长度差
2.长的链表先走几步
3.此时链表长度相同，同时遍历链表寻找交点即可

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
        if(headA==null||headB==null){
            return null;
        }
        int lengtha=getnodelength(headA);
        int lengthb=getnodelength(headB);
        
        ListNode a=headA;
        ListNode b=headB;
        
        if(lengtha>lengthb){
          for(int i=0;i<lengtha-lengthb;i++){
              a=a.next;
          }  
        }
      if(lengtha<lengthb){
          for(int i=0;i<lengthb-lengtha;i++){
              b=b.next;
          }  
        }
    while(a!=null){
        if(a.equals(b)){
            return a;
        }
        a=a.next;
        b=b.next;
    }
 return null;
    }
    public int getnodelength(ListNode head){
        ListNode node=head;
        int count =0;
         while(node!=null){
             count++;
             node=node.next;
         }

        return count;
    }
}
```