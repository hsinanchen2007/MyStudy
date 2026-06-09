### 解题思路
为避免使用太多额外空间，总体思路是将输入链表的前半部分反转过来，然后从中间往两端进行匹配，最后再将链表还原回去，总体是O(N)时间,O(1)空间

如先将 1->2->3->4->4->3->2->1 变成   1<-2<-3<-4   4->3->2->1
再从中间往两本匹配

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
    public boolean isPalindrome(ListNode head) {
        if(head == null)
            return true;

        // 翻转前需要知道链表总体长度，所以先遍历一遍求len
        int len = 0;
        ListNode node = head;
        while(node != null){
            node = node.next;
            len++;
        }
        if(len == 1)
            return true;

        // 将前半段链表的next指针反转
        ListNode pre = null, cur = head, next = cur;
        for(int i = 0; i < len / 2; i++){
            next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
        }

        // 保存断开点指针，方便后续恢复链表
        ListNode breakpoint = cur, breakpre = pre;

        // 判断链表是否回文
        boolean ans = true;
        // 如果是奇数个节点，中间节点不需要判断
        if(len % 2 != 0)
            cur = cur.next;
        while(cur != null){
            if(cur.val == pre.val){
                cur = cur.next;
                pre = pre.next;
            } else {
                ans = false;
                break;
            }
        }

        //恢复链表
        cur = breakpre;
        next = cur.next;
        pre = breakpoint;
        while(cur != null){
            next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
        }

        return ans;
    }
}
```