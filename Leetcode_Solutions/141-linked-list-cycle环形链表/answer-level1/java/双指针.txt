### 解题思路
此处撰写解题思路
使用双指针，一个指针每次移动一次，一个指针每次移动两次，如果存在环，这两个指针一定会重合。
### 代码

```java
/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        if(head==null) return false;
        ListNode l1=head,l2=head.next;
        while(l1!=null&&l2!=null){
            if(l1==l2) return true;
            l1=l1.next;
            if(l2.next==null) break;
            l2=l2.next.next;
        }
        return false;  
    }
}
```