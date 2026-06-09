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
        if (l1==null) return  l2;
        if (l2==null) return  l1;
        if (l1==null&&l2==null) return null;
        //3->4->7
        //5->8->9->2
        ListNode result = new ListNode(0);
        ListNode current = result;
        int count = 0;
        while (l1!=null&&l2!=null){
            int val1 = l1.val;
            l1 = l1.next;
            int val2 = l2.val;
            l2 = l2.next;
            int sum = val1+val2+count;
            int number = sum%10;
            count = sum/10;
            current.next = new ListNode(number);
            current = current.next;
        }
        while (l1!=null){
            int val1 = l1.val;
            l1 = l1.next;
            int sum = val1+count;
            int number = sum%10;
            count = sum/10;
            current.next = new ListNode(number);
            current = current.next;
        }
        while (l2!=null){
            int val2 = l2.val;
            l2 = l2.next;
            int sum = val2+count;
            int number = sum%10;
            count = sum/10;
            current.next = new ListNode(number);
            current = current.next;
        }
        if (l1==null&&l2==null&&count>0){
            current.next = new ListNode(count);
            current = current.next;
        }
        return  result.next;
    }
}
```