```
class Solution {
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        int len1 = 0, len2 = 0;
        ListNode cur1 = l1;
        ListNode cur2 = l2;
        while(cur1 != null)
        {
            cur1 = cur1.next;
            len1++;
        }
        while(cur2 != null)
        {
            cur2 = cur2.next;
            len2++;
        }
        if(len1 < len2)
            return addTwoNumbers(l2, l1);
        if(getCarry(l1, l2, len1 - len2) != 0)
        {
            ListNode prev = new ListNode(1);
            prev.next = l1;
            l1 = prev;
        }
        return l1;
    }
    
    public int getCarry(ListNode l1, ListNode l2, int diff) {
        if(l1 == null || l2 == null)
            return 0;

        int sum = 0;
        if(diff > 0)//l1比l2多出的部分 所以不加l2
            sum = l1.val + getCarry(l1.next, l2, diff - 1);
        else
            sum = l1.val + l2.val + getCarry(l1.next, l2.next, diff);
        l1.val = sum % 10;
        return sum / 10;
    }
}
```
