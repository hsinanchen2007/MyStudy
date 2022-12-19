### 解题思路

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
       int firstCount = 0;
       int secondCount = 0;
       ListNode oriL1 = l1;
       ListNode oriL2 = l2;
       while(l1 !=null || l2 !=null)  {
           if(l1 != null) { firstCount++; l1=l1.next; }
           if(l2 != null) { secondCount++; l2=l2.next;}
       }
       l1 = oriL1;
       l2 = oriL2;
       if(firstCount < secondCount) {
           ListNode tmp = l2;
           l2 = l1;
           l1 = tmp;
       }

       int diff = Math.abs(firstCount - secondCount);
       if(firstCount == 0) { return null; }

       ListNode pre = new ListNode(0);
       int carry = add(pre,l1,l2,diff);
       if(carry == 1) {
           pre.val = 1;
           return pre;
       } else {
           return pre.next;
       }
    }

    private int add(ListNode pre,ListNode l1,ListNode l2,int diff) {
        if(l1 == null) {
            return 0;
        }
        ListNode curr = new ListNode(0);
        int carryVal = 0;
        if(diff > 0) {
            carryVal = add(curr,l1.next,l2,diff-1);
        } else {
            carryVal = add(curr,l1.next,l2.next,0);
        }
        int sum = l1.val + carryVal;
        if(diff <= 0) {
            sum += l2.val;    
        }
        carryVal = 0;
        if(sum > 9) {
            sum = sum -10;
            carryVal = 1;
        }
        curr.val = sum;
        pre.next = curr; 
        return carryVal;
    }
}
```