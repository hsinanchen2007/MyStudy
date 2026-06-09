### 解题思路
先两个链表合并
接着采用分治的思想，处理。这里着重说明一下为啥这样搞：
如果采用遍历的方式，前面的链表会非常长，比如：
【1，2,3,4,5,7,8,9,10,22,56,78,79,88,98】与【79,88】合并，其实这样能看出来大的链表白白遍历那么多次了。
如果采用分治，两两结合，就不会造成链表很长，遍历时间很长的问题！！！

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
        if (lists == null || lists.length == 0) {
            return null;
        }
        if (lists.length == 1) {
            return lists[0];
        }
        return mergeByDivision(lists,0,lists.length-1);
    }


    public ListNode mergeByDivision(ListNode[] lists, int start, int end) {
        if (start == end) {
            return lists[end];
        }
        if (start + 1 == end) {
            return mergeTwoNode(lists[start], lists[end]);
        }
        int mid = (start + end) >>> 1;
        ListNode left = mergeByDivision(lists, start, mid);
        ListNode rightNode = mergeByDivision(lists, mid+1, end);
        return mergeTwoNode(left, rightNode);
    }


    private ListNode mergeTwoNode(ListNode node1, ListNode node2) {
        if (node1 == null && node2 != null) {
            return node2;
        }
        if (node2 == null && node1 != null) {
            return node1;
        }
        if (node1 == null && node2 == null) {
            return null;
        }
        ListNode tmpNode1 = node1;
        ListNode tmpNode2 = node2;
        ListNode initNode = new ListNode(-1);
        ListNode preNode = initNode;
        while (tmpNode1 != null || tmpNode2 != null) {
            if (tmpNode1 == null) {
                preNode.next = tmpNode2;
                preNode = preNode.next;
                tmpNode2 = tmpNode2.next;
                continue;
            }
            if (tmpNode2 == null) {
                preNode.next = tmpNode1;
                preNode = preNode.next;
                tmpNode1 = tmpNode1.next;
                continue;
            }
            if (tmpNode1.val < tmpNode2.val) {
                preNode.next = tmpNode1;
                preNode = preNode.next;
                tmpNode1 = tmpNode1.next;
            } else {
                preNode.next = tmpNode2;
                preNode = preNode.next;
                tmpNode2 = tmpNode2.next;
            }
        }
        return initNode.next;
    }
    
}
```