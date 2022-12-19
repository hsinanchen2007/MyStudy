执行用时 :0 ms, 在所有 java 提交中击败了100.00% 的用户
内存消耗 :36.6 MB, 在所有 java 提交中击败了93.63%的用户
```
class Solution {
    public ListNode oddEvenList(ListNode head) {
        if(head == null || head.next == null || head.next.next == null)
            return head;
        ListNode odd = head;
        ListNode tempOdd = odd;
        ListNode even = head.next;
        ListNode tempEven = even;
        head = head.next.next;
        while(head != null){
            odd.next = head;
            even.next = head.next;
            odd = odd.next;
            even = even.next;
            if(head.next == null)
                break;
            head = head.next.next;
            
        }
       // even.next = null;
        odd.next = tempEven;
        return tempOdd;
    }
}
```
