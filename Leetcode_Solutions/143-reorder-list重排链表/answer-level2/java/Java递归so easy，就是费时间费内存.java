### 解题思路
递归解法很简单，就是找到倒数第一个和倒数第二个节点。然后改变一下next指针即可。

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
    public void reorderList(ListNode head) {
        reorderListRec(head);
    }

    public ListNode reorderListRec(ListNode head){
        if(head == null || head.next == null || head.next.next == null)
            return head;
        ListNode pre = head;
        ListNode cur = head.next;
        while(cur.next != null){
            pre = cur;
            cur = cur.next;
        }
        pre.next = null;
        ListNode next = head.next;
        head.next = cur;
        cur.next = reorderListRec(next);
        return head;
    }
}
```
非递归解法
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
    public void reorderList(ListNode head) {
if(head == null || head.next == null || head.next.next == null)
            return;
        //找出中间节点
        ListNode preMid = head;
        ListNode cur = head.next;//中间节点前面的节点
        ListNode mid = head.next.next;
        while(mid != null && mid.next != null && mid.next.next != null){
            if(mid == null || mid.next == null || mid.next.next == null)
                break;
            preMid = cur;
            cur = cur.next;
            mid = mid.next.next;
        }
        if(mid.next != null)
            preMid = preMid.next;

        ListNode laterNode = preMid.next;
        preMid.next = null;
        //将laterNode翻转
        ListNode pre =  null;
        cur = laterNode;
        while(cur != null){
            ListNode next = cur.next;
            cur.next = pre;
            pre = cur;
            cur = next;
        }
        //将pre和head合并
        cur = head;
        int index= 0;
        while(cur != null && pre != null){
            if(index % 2 == 0){
                ListNode next = cur.next;
                cur.next = pre;
                cur = next;
            }else{
                ListNode next = pre.next;
                pre.next = cur;
                pre = next;
            }
            index++;
        }
        return;
    }
}
```