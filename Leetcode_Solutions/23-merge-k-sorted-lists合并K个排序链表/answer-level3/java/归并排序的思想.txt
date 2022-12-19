### 解题思路
归并排序的思想

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
        int length = lists.length;
        if(length == 0) return null;
        return merge(lists, 0, length - 1);
    }

    private ListNode merge(ListNode[] lists, int l, int r){
        if(l == r) return lists[l];
        int mid = (l + r) / 2;
        ListNode leftNode = merge(lists, l, mid);
        ListNode righNode = merge(lists, mid+1, r);
        ListNode head = new ListNode(0);
        ListNode _head = head;
        while(leftNode != null && righNode != null){
            if(leftNode.val < righNode.val){
                head.next = leftNode;
                head = leftNode;
                leftNode = leftNode.next;
                head.next = null;
            }else{
                head.next = righNode;
                head = righNode;
                righNode = righNode.next;
                head.next = null;
            }
        }
        while(leftNode != null){
            head.next = leftNode;
            head = leftNode;
            leftNode = leftNode.next;
            head.next = null;
        }
        while(righNode != null){
            head.next = righNode;
            head = righNode;
            righNode = righNode.next;
            head.next = null;
        }
        return _head.next;
    }
}
```