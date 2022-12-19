### 解题思路
执行用时 :2 ms, 在所有 Java 提交中击败了100.00%的用户
内存消耗 :40.7 MB, 在所有 Java 提交中击败了86.61%的用户

先反转两个链表，然后比较两个链表哪一个长一点，以长的链表作为while的条件进行遍历，相同位数的相加，
然后在遍历长链表的时候顺便给它又反转成原来的正序

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
        int length1 = 0;
        int length2 = 0;
        ListNode pre1 = null;
        ListNode pre2 = null;
        while(l1 != null){
            ListNode next = l1.next;
            l1.next = pre1;
            pre1 = l1;
            l1 = next;
            length1++;
        }
        while(l2 != null){
            ListNode next = l2.next;
            l2.next = pre2;
            pre2 = l2;
            l2 = next;
            length2++;
        }
        ListNode max = null;
        ListNode min = null;
        if(length1 >= length2){
            max = pre1;
            min = pre2;
        }else{
            max = pre2;
            min = pre1;
        }
        ListNode pre3 = null;
        int flag = 0;
        while(max != null){
            int minVal = min==null?0:min.val;
            if((max.val + minVal + flag) >= 10){ 
                max.val = (max.val + minVal + flag) % 10;
                flag = 1;
            }else{
                max.val = max.val + minVal + flag;
                flag = 0;
            }
            ListNode next = max.next;
            max.next = pre3;
            pre3 = max;
            max = next;
            if(min != null){
                min = min.next;
            }
        }
        if(flag == 1 ){
            ListNode head = new ListNode(1);
            head.next = pre3;
            return head;
        }
        return pre3;
    }

}
```