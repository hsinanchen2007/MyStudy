### 解题思路
这道题是一个经典的数据结构中合并链表算法，比较常规

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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode res = new ListNode(0);
        ListNode L = res;
        L.next = null;
        while(l1!=null && l2!=null){
            if(l1.val <= l2.val){
                L.next = l1;
                L = L.next;
                l1 = l1.next;
                L.next = null;
            }else{
                L.next = l2;
                L = L.next;
                l2 = l2.next;
                L.next = null;
            }
        }
        if(l1==null){
            while(l2!=null){
                L.next = l2;
                l2 = l2.next;
                L = L.next;
                L.next = null;
            }
        }
        if(l2==null){
            while(l1!=null){
                L.next = l1;
                l1 = l1.next;
                L = L.next;
                L.next = null;
            }
        }
        return res.next;
    }
}
```