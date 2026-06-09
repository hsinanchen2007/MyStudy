### 解题思路
此处撰写解题思路
1、采用归并思想，进行递归合并
2、将多个排序合并，转化成最终两个序列合并
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
    public ListNode mergeKLists(ListNode[] lists) {
        if (lists.length == 1) return lists[0];
        return partition(lists,0,lists.length - 1);
    }
    public ListNode partition(ListNode[] lists, int low, int high) {
        if (low == high) return lists[low];
        if (low < high) {
            int medium = (low + high) / 2;
            ListNode l = partition(lists, low, medium);
            ListNode h = partition(lists, medium + 1, high);
            return mergeListNode(l, h);
        }
        return null;
    }
    public ListNode mergeListNode(ListNode one, ListNode other){
        if (one == null && other != null) return other;
        if (one != null && other == null) return one;
        if (one == null && other == null) return null;
        ListNode p = new ListNode(0);
        ListNode result = p;
        while (one != null && other != null) {
            if (one.val < other.val) {
                p.next = one;
                one = one.next;
            }
            else {
                p.next = other;
                other = other.next;
            }
            p = p.next;
        }
        while (one != null) {
            p.next = one;
            one = one.next;
            p = p.next;
        }
        while (other != null) {
            p.next = other;
            other = other.next;
            p = p.next;
        }
        return result.next;
    }
}
```