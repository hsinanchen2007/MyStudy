```
/**
    归并合并 
        1: {0,1} {2,3} {3,4} {5,6}
        2: {0,1,2,3} {3,4,5,6}
        3: {0,1,2,3,4,5,6}
 */
public class Solution {
    public ListNode MergeKLists(ListNode[] lists) {
        int length = lists.Length;
        if (length == 0) {
            return null;
        }
        return MergeRecursive(lists, 0, length - 1);
    }

    // 递归方法
    public ListNode MergeRecursive(ListNode[] lists, int low, int high) {
        if (low == high) {
            return lists[low];
        }
        int mid = (low + high) >> 1;
        ListNode node1 = MergeRecursive(lists, low, mid);
        ListNode node2 = MergeRecursive(lists, mid + 1, high);
        return Merge(node1, node2);
    }

    // 合并两个链表
    public ListNode Merge(ListNode node1, ListNode node2) {
        ListNode preNode = new ListNode(-1);
        ListNode node = preNode;
        while (node1 != null && node2 != null) {
            if (node1.val > node2.val) {
                node.next = node2;
                node2 = node2.next;
            } else {
                node.next = node1;
                node1 = node1.next;
            }
            node = node.next;
        }
        node.next = node1 != null ? node1 : node2;
        return preNode.next;
    }
}
```
