### 解题思路
![捕获1.PNG](https://pic.leetcode-cn.com/8af6d5631e8e81bffb53168884827b2a975432e956bd6e4afc4b0ea07531f8a4-%E6%8D%95%E8%8E%B71.PNG)


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
    public ListNode reverseList(ListNode head) {
        ListNode nHead=null;
        ListNode cur=head;
        while(cur!=null){
            ListNode next=cur.next;
            cur.next=nHead;
            nHead=cur;
            cur=next;
        }
        return nHead;
    }
}
```