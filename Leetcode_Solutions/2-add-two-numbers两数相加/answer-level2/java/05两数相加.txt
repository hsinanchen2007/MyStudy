不习惯用链表
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
        if(l1 == null && l2 == null)
            return null;
        int x = 0;
        int a = 0;
        int b = 0;
        if(l1 != null){
            a = l1.val;
            l1 = l1.next;
        }
        if(l2 != null){
            b = l2.val;
            l2 = l2.next;
        }
        int res = (a + b) % 10;
        x = (a + b) / 10;
        ListNode test = new ListNode(res);
        ListNode result = test;
        while(l1 != null && l2 != null){
            a = l1.val;
            b = l2.val;
            res= (a + b + x) % 10;
            x = (a + b + x) / 10;
            ListNode list = new ListNode(res);
            test.next = list;
            test = test.next;
            l1 = l1.next;
            l2 = l2.next;
        }
        while (l1 != null){
            a = l1.val;
            res= (a + x) % 10;
            x = (a + x) / 10;
            ListNode list = new ListNode(res);
            test.next = list;
            test = test.next;
            l1 = l1.next;
        }
        while (l2 != null){
            a = l2.val;
            res= (a + x) % 10;
            x = (a + x) / 10;
            ListNode list = new ListNode(res);
            test.next = list;
            test = test.next;
            l2 = l2.next;
        }
        if(x != 0){
            ListNode list = new ListNode(x);
            test.next = list;
            test = test.next;
        }
        /*while (result != null){
            System.out.println(result.val);
            result = result.next;
        }*/
        return result;
    }
}