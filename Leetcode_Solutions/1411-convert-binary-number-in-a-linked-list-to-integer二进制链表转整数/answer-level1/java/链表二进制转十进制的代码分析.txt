### 解题思路
详见代码注释

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
    public int getDecimalValue(ListNode head) {
        ListNode cur = head;
        int res = 0;
        while (cur != null) {
            //cur指针右移一位            
            //--1-- res:0  cur.val: 1 --> res:1   0 * 2 +  1
            //--2-- res:1  cur.val: 0 --> res:2   1 * 2 +  0
            //--3-- res:2  cur.val: 1 --> res:5   2 * 2 +  1
            //res:5 --> (((0 * 2 +  1) *2  + 0 ) *2   + 1 
            //                      1* 2^2  + 0 * 2^1 + 1 * 2^0     
            res = res *2 + cur.val;
            cur = cur.next;
        }
    return res;
    }
}
```