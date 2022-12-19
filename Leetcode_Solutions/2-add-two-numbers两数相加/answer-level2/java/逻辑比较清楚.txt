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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode head = null;
        ListNode pointT = null;
        ListNode point = null;
        ListNode pointL1 = l1;
        ListNode pointL2 = l2;
        int pop= 0;
        while (null != pointL1 || null != pointL2) {
            if (pointL1 != null && pointL2 != null) {
                pointT = new ListNode((pointL1.val + pointL2.val+pop)%10);
                pop = (pointL1.val + pointL2.val+pop)/10;
            } else {
                pointT = new ListNode(null != pointL1?(pointL1.val+pop)%10:(pointL2.val+pop)%10);
                pop = null != pointL1?(pointL1.val+pop)/10:(pointL2.val+pop)/10;
            }
            if(null == point){
                point =pointT;
            } else {
                point.next = pointT;
                point= point.next;
            }
            pointL1 =(null==pointL1)?pointL1:pointL1.next;
            pointL2 =(null==pointL2)?pointL2:pointL2.next;
            head = null == head?pointT:head;
        }
        if(0 !=pop ){
            point.next = new ListNode(pop);
        }
        return head;
    }
}
```