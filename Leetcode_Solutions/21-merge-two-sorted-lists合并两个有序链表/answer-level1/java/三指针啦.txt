### 解题思路
三指针，各管一个ListNode完成遍历就行啦
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
        // 三指针法
        ListNode root = new ListNode(-1);
        ListNode temp = root;
        ListNode l = l1;
        ListNode r = l2;
        while(l != null && r != null){
            if(l.val > r.val){
                root.next = new ListNode(r.val);
                r = r.next;
            }else{
                root.next = new ListNode(l.val);
                l = l.next;
            }
            root = root.next;
        }
        while(l != null){
            root.next = new ListNode(l.val);
            root = root.next;
            l  = l.next;
        }
        while(r != null){
            root.next = new ListNode(r.val);
            root = root.next;
            r  = r.next;
        }
        return temp.next;
    }
}
```