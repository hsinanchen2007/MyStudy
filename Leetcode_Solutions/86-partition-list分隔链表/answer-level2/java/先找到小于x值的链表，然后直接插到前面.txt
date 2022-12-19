### 解题思路
找两个例子模拟一遍就能得解题思路，和删除节点一样

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
    public ListNode partition(ListNode head, int x) {

        ListNode pre = new ListNode(0);
        pre.next = head;
        ListNode res = pre;
        ListNode l1 = new ListNode(0);
        ListNode l2 = l1;;
        while(head!=null){
            if(head.val<x){
                pre.next = head.next;
                l1.next = head;
                l1 = head;
            }
            else
                pre = head;
            head=head.next;

        }
        l1.next = res.next;
        return l2.next;

    }
}
```