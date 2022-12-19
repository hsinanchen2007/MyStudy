分治法思想 递归的两两合并 执行logk次
```
/*
 * @lc app=leetcode.cn id=23 lang=csharp
 *
 * [23] 合并K个排序链表
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     public int val;
 *     public ListNode next;
 *     public ListNode(int x) { val = x; }
 * }
 */
public class Solution {
    public ListNode MergeKLists(ListNode[] lists) {
        if(lists==null||lists.Length==0)
        return null;
        return Merge(lists,0,lists.Length-1);
    }

    public ListNode Merge(ListNode[] lists,int start,int end)
    {
        if (start>=end)
        {
            return lists[start];
        }
 
        int mid = start+(end-start)/2;
        ListNode l1 = Merge(lists,start,mid);
        ListNode l2 = Merge(lists,mid+1,end);
        return mergeTwoLists(l1,l2);
    }
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode dummyNode = new ListNode(-1);
        ListNode pre = dummyNode;
        if(l1==null)
        {
            return l2;
        }
        if(l2==null)
        {
            return l1;
        }
        while(l1!=null&&l2!=null)
        {
            if(l1.val>=l2.val)
        {
            pre.next = l2;
            l2 = l2.next;
        }
        else
        {
            pre.next= l1;
            l1 = l1.next;
        }
        pre = pre.next;
        }
        
        if(l1!=null)
        {
            pre.next = l1;
        }
        if(l2!=null)
        {
            pre.next = l2;
        }
        return dummyNode.next;
    }
}
// @lc code=end


```
