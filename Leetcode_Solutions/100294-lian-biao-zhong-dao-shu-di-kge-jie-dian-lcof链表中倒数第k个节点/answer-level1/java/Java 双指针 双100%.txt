### 解题思路
此处撰写解题思路

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
    public ListNode getKthFromEnd(ListNode head, int k) {
        //定义快慢两个指针，快指针先走k-1，然后两个指针同步移动，当快指针next为空时，返回慢指针
        ListNode q = head,s = head;
        for(int i = 0; i < k-1; i ++){
            q = q.next;
        }
        while(q.next != null){
            q = q.next;
            s = s.next;
        }
        return s;
    }
}
```