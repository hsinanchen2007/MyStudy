C#
```
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode AddTwoNumbers(ListNode l1, ListNode l2) {
        ListNode lResult = new ListNode(0);
        ListNode lResCursor = lResult;
        ListNode ll1Cursor = l1;
        ListNode ll2Cursor = l2;
        int carryFlag = 0;
        int digitSum = 0;
        while(ll1Cursor != null || ll2Cursor != null || carryFlag == 1)
        {  
            digitSum = (ll1Cursor == null ? 0 : ll1Cursor.val) + (ll2Cursor == null? 0 : ll2Cursor.val) + carryFlag;
            carryFlag = digitSum /10;

         
            lResCursor.next = new ListNode(digitSum % 10);
            lResCursor = lResCursor.next;
            if(ll1Cursor != null)
            {
                ll1Cursor = ll1Cursor.next;
            }
            if(ll2Cursor != null)
            {
                ll2Cursor = ll2Cursor.next;
            }
        }
        
        return lResult.next;
    }
}
```
