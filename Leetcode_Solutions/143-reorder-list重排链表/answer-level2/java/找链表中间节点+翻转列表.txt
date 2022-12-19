### 解题思路
第1步：利用快指针（一次走2步），慢指针（一次走一步），找到链表中间节点，将链表分为两部分
第2步：翻转后半段链表
//第3步：将后端链表节点依次插入前端链表中
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
        if(head==null){
            return;
        }
        //第1步：利用快指针（一次走2步），慢指针（一次走一步），找到链表中间节点，将链表分为两部分
        ListNode slow = head;
        ListNode fast = head;
        while(fast.next != null && fast.next.next!=null){
            slow = slow.next;
            fast = fast.next.next;
        }
        if(fast.next !=null && fast.next.next == null){
            slow = slow.next;
        }
        ListNode middle = slow.next;
        if(middle==null){
            return;
        }
        slow.next = null;
        //第2步：翻转后半段链表
        //建立哑结点
        ListNode preMiddle = new ListNode(-1);
        preMiddle.next = middle;
        ListNode cur = middle.next;
        middle.next = null;
        while(cur!=null){
            ListNode tmp = cur.next;
            cur.next = preMiddle.next;
            preMiddle.next = cur;
            cur = tmp;
        }

        //第3步：将后端链表节点依次插入前端链表中
        ListNode curMiddle = preMiddle.next;
        ListNode curBefore = head;
        while(curMiddle!=null && curBefore!=null){
            ListNode tmpCurNext = curBefore.next;
            ListNode tmpMiddleNext = curMiddle.next;
            curBefore.next = curMiddle;
            curMiddle.next = tmpCurNext;
            curBefore = tmpCurNext;
            curMiddle = tmpMiddleNext;
        }
    }
}
```