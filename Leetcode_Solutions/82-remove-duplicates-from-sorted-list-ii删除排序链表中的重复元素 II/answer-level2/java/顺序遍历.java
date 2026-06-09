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
    public ListNode deleteDuplicates(ListNode head) {
        // first -> 1 -> 2 -> 3 -> 3' -> 4 -> 4' -> 5
        // pre      c
        // c.val != c.next.val -> pre = pre.next, c = c.next 
        
        // fist -> 1 -> 2 -> 3 -> 3' -> 4 -> 4' -> 5
        //         pre  c
        // c.val != c.next.val -> pre = pre.next, c = c.next
        
        // first -> 1 -> 2 -> 3 -> 3' -> 4 -> 4' -> 5
        //               pre  c    
        // c.val == c.next.val -> (pre.next = while(c.val == c.next.val)), c = pre.next;
        
        // first -> 1 -> 2 -> 4 -> 4' -> 5
        //             pre  c    
        // c.val == c.next.val -> (pre.next = while(c.val == c.next.val)), pre.next = c;
        
        // first -> 1 -> 2 -> 5
        //               pre  c
        
        if(head == null) return null;
        
        ListNode first = new ListNode(-1);
        first.next = head;
        
        ListNode pre = first, c = pre.next;
        while(c != null && c.next != null){
            if(c.val != c.next.val){
                pre = pre.next;
                c = c.next;
            }else{
                int del = c.val;
                while(c != null && c.val == del){
                    c = c.next;
                }
                pre.next = c;
            }
        }
        
        return first.next;
    }
}
```


![image.png](https://pic.leetcode-cn.com/e7438df0507b15cec6e807c93d015712fb7cbd2e47e361fd999e0913a96cf267-image.png)
