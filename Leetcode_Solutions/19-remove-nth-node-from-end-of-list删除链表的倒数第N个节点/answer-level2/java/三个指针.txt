### 解题思路
cur存遍历的指针
pre存前驱
target存要删除的
用pre是否等于target来判断是否删除头结点

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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode cur = head;
        ListNode target = head;
        ListNode pre = head;
        ListNode ans = new ListNode(0);
        ans.next = head;
        while(n != 1){
            cur = cur.next;
            n--;
        }
        target = head;
        while(cur.next!=null){
            pre = target;
            target = target.next;
            cur = cur.next;
        }
        if(pre == target) return head.next;
        ListNode temp = target.next;
        pre.next = temp;
        ListNode res = ans.next;

        return res;
    }
}
```