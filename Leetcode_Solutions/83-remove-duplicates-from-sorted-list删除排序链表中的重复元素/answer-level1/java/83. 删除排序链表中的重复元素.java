注意点：循环条件中要设置 pre != null && pre.next != null 缺一不可 否则会空指针异常

```
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
        //删除操作需要知道被删除结点A的前置结点和A的下一个结点
        ListNode pre = head;
        //此处pre也需要判断 防止传入空
        while (pre != null && pre.next != null) {
            if (pre.next.val == pre.val) {
                pre.next = pre.next.next;
            }
            //必须用else 因为可能有多个连续重复的结点
            else{
                pre = pre.next;
            }
        }
        return head;
    }
}
```
