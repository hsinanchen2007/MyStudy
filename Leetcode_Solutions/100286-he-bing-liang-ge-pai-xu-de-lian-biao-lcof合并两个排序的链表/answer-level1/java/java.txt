### 解题思路


### 代码
第一种普通思路，双指针同时遍历
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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode temp = new ListNode(-1);
        ListNode result = temp;
        if(l1 ==null){
            return l2;
        }
        if(l2 ==null){
            return l1;
        }
        while(l1 !=null && l2!=null){
            if(l1.val<=l2.val){
                temp.next = l1;
                l1 = l1.next;
            }else{
                temp.next = l2;
                l2 = l2 .next;
            }
            temp = temp.next;
        }
        if(l1 !=null || l2!=null)
            temp.next = l1!=null?l1:l2;
        return result.next;
        }
}
```
第二种，递归处理。
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {

        if(l1 ==null){
            return l2;
        }
        if(l2 ==null){
            return l1;
        }
        ListNode newNode;
        if(l1.val<=l2.val){
            newNode = l1;
            newNode.next = mergeTwoLists(l1.next,l2);
        }else{
            newNode = l2;
            newNode.next = mergeTwoLists(l1,l2.next);
        }
        return newNode;

        }
}