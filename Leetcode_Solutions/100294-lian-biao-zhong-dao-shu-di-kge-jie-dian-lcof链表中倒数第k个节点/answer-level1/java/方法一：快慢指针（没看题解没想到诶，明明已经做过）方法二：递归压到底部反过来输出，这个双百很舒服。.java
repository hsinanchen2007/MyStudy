### 解题思路
此处撰写解题思路

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
   int num = 0;
    ListNode res = null;
    public ListNode getKthFromEnd(ListNode head, int k) {
     
     if(head==null)
       return res;
     
     getKthFromEnd(head.next,k);
     num++;

     if(num==k){
         res = head;
     }

     return res;
       
    
       
    }
}
```