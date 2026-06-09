### 解题思路
写两个用例 模拟一下就很容易写出来了，主要注意的是边界条件

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
    public ListNode deleteDuplicates(ListNode head) {
        ListNode pre = new ListNode(0);
        ListNode res = pre;
        pre.next = head;
        while(head!=null){
            int val = head.val;
            if(head.next!=null&&head.next.val==val){
                while(head.next!=null){
                    if(head.next.val != val)
                        break;
                    head = head.next;
                }
                pre.next = head.next;
            }
            else
                pre = head;
            head = head.next;
        }
        return res.next;
    }
}
```