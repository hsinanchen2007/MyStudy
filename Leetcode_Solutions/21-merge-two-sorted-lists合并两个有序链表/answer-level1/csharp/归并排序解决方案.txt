### 解题思路
就是归并排序，除开那个划分而已啊

### 代码
public ListNode MergeTwoLists(ListNode l1, ListNode l2) {
            ListNode i = l1;
            ListNode j = l2;
            ListNode head = null;
            if(i==null&&j==null)
            {
                return null;
            }
            else if(i==null)
            {
                head = j;
                j = j.next;
            }
            else if(j==null)
            {
                head = i;
                i = i.next;
            }
            else if (i.val < j.val)
            {
                head = i;
                i = i.next;
            }
            else
            {
                head = j;
                j = j.next;
            }
            ListNode cur = head;
            while (i != null && j != null)
            {
                if (i.val < j.val)
                {
                    cur.next = i;
                    i = i.next;
                }
                else
                {
                    cur.next = j;
                    j = j.next;
                }
                cur = cur.next;
            }
            while (i != null)
            {
                cur.next = i;
                i = i.next;
                cur = cur.next;
            }
            while (j != null)
            {
                cur.next = j;
                j = j.next;
                cur = cur.next;
            }
            return head;
    }
```csharp
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode MergeTwoLists(ListNode l1, ListNode l2) {
            ListNode i = l1;
            ListNode j = l2;
            ListNode head = null;
            if(i==null&&j==null)
            {
                return null;
            }
            else if(i==null)
            {
                head = j;
                j = j.next;
            }
            else if(j==null)
            {
                head = i;
                i = i.next;
            }
            else if (i.val < j.val)
            {
                head = i;
                i = i.next;
            }
            else
            {
                head = j;
                j = j.next;
            }
            ListNode cur = head;
            while (i != null && j != null)
            {
                if (i.val < j.val)
                {
                    cur.next = i;
                    i = i.next;
                }
                else
                {
                    cur.next = j;
                    j = j.next;
                }
                cur = cur.next;
            }
            while (i != null)
            {
                cur.next = i;
                i = i.next;
                cur = cur.next;
            }
            while (j != null)
            {
                cur.next = j;
                j = j.next;
                cur = cur.next;
            }
            return head;
    }
}
```