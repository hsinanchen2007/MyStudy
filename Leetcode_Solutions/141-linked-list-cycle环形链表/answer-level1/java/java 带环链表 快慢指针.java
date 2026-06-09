### 解题思路
    快指针和慢指针从头开始走，快的走两步，慢的走一步，如果 两个指针相遇则存在环，返回true；否则false。
    需要注意：快指针的next 如果是null,返回false，需要判断一下，不然会报错。

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
        if(head==null || head.next==null){
            return false;
        }
        ListNode node=head,pre=head;
        while(pre!=null && node!=null){
            if(pre.next!=null){
                pre=pre.next.next;
                node = node.next;
                if(node==pre){
                   return true;
                }
            }else{
                return false;
            }
        }
        return false;
    }
}
```