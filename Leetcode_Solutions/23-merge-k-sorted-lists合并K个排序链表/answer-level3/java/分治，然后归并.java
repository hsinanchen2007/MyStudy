### 解题思路
二路分治，归并结果
分治：把k个链表合并问题分解成2个链表合并。

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
        if(lists.length == 0) {
            return null;
        }
        return mergeKLists(lists, 0, lists.length - 1);
    }

    public ListNode mergeKLists(ListNode[] lists, int start, int end) {
        if(start == end) {
            return lists[start];
        }
        if((end - start) == 1) {
            return merge2List(lists[start], lists[end]);
        }
        int temp = (end + start)/2;
        ListNode one = mergeKLists(lists, start , temp);
        ListNode two = mergeKLists(lists, temp + 1, end);
        return merge2List(one, two);
    }

    public ListNode merge2List(ListNode list1, ListNode list2) {
        if(list1 == null) {
            return list2;
        }
        if(list2 == null) {
            return list1;
        }
        ListNode head,cur,one,two;
        if(list1.val > list2.val) {
            head = list2;
            one = list1;
            two = list2.next;
        } else {
            head = list1;
            one = list1.next;
            two = list2;
        }
        cur = head;
        while(one != null && two != null) {
            if(one.val > two.val) {
                cur.next = two;
                cur = two;
                two = two.next;
            } else {
                cur.next = one;
                cur = one;
                one = one.next;
            }
        }
        if(one != null) {
            cur.next = one;
        }
        if(two != null) {
            cur.next = two;
        }
        return head;
    }

}
```