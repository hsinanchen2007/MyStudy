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
        int n = 0;
        int temp;
        ListNode result = l1;
        ListNode r=l1;
        while(l1!=null&&l2!=null){
            temp=l1.val+l2.val+n;
            n=temp/10;
            temp=temp%10;
            l1.val = temp;
            r=l1;
            l1=l1.next;
            l2=l2.next;
        }
        if(l1==null){
            r.next=l2;
            l1=r.next;
        }
        while(l1!=null){
            temp=l1.val+n;
            n=temp/10;
            temp=temp%10;
            l1.val = temp;
            r=l1;
            l1=l1.next;
        }
        if(n!=0){
            ListNode add = new ListNode(n);
            r.next=add;
        }
        return result;

    }
}
```