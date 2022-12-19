### 解题思路
此处撰写解题思路

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
        if(headA==null ||headB==null){
            return null;
        }
        int lena=0;
        int lenb=0;
        ListNode a=headA;
        ListNode b=headB;
        while(a.next!=null){
            a=a.next;
            lena++;
        }
        lena++;
        while(b.next!=null){
            b=b.next;
            lenb++;
        }
        lenb++;
        a=headA;
        b=headB;
        if(lena>lenb){
            while(lena>lenb){
                a=a.next;
                lena--;
            }
            
        }else if(lenb>lena){
            while(lenb>lena){
                b=b.next;
                lenb--;
            }
        }
        while(a!=b){
                a=a.next;
                b=b.next;
            }
            return a;
    }
}
```