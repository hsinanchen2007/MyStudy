没有用额外空间，直接在链表上操作：
```
/*
 * @lc app=leetcode.cn id=83 lang=csharp
 *
 * [83] 删除排序链表中的重复元素
 */
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode DeleteDuplicates(ListNode head) {
        if (head == null)
        {
            return null;
        }

        var rememberTop = head;
        var next = head.next;
        while(head != null && next != null)
        {
            if(next.val == head.val)
            {
                next = next.next;
                head.next = next;
            }
            else
            {
                head = head.next;
                next = head.next;
            }
        }

        return rememberTop;
    }
}


```
