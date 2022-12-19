# **分而治之的思想，参考归并排序**

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
    public ListNode mergeKLists(ListNode[] lists) {
        if(lists.length == 0) return null;
        return startMergeKLists(lists, 0, lists.length - 1);
    }
    public ListNode startMergeKLists(ListNode[] lists, int left, int right){
        if(left == right) return lists[left];
        int mid = (left + right) / 2;
        ListNode l1 = startMergeKLists(lists, left, mid);
        ListNode l2 = startMergeKLists(lists, mid + 1, right);
        return mergeLists(l1, l2);
    }
    public ListNode mergeLists(ListNode l1, ListNode l2){
        ListNode l3 = new ListNode(-1);
        ListNode temp = l3;
        while(l1 != null && l2 != null){
            if(l1.val < l2.val){
                temp.next = l1;
                l1 = l1.next;
            }else {
                temp.next = l2;
                l2 = l2.next;
            }
            temp = temp.next;
        }
        temp.next = l1 != null ? l1 : l2;
        return l3.next;
    }
}
```


