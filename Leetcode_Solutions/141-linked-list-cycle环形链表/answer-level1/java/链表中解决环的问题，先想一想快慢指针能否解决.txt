### 解题思路
当时盯着这道题的图看了一会，想到了利用快慢指针的思想，就是让一个指针移动的比另一个指针的快，如果有环的话，指针快的一定会追到指针慢的

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
        //利用快慢指针的原理
        if(head==null){
            return false;
        }
        ListNode preHead = new ListNode(-1);
        preHead.next = head;
        ListNode slow = preHead;
        ListNode fast = slow.next;
        boolean flag = false;//默认没有环
        while(fast.next!=null){
            if(fast.next==slow){
                flag = true;
                break;
            }else{
                fast = fast.next.next;
                slow = slow.next;
                if(fast==null){
                    flag = false;
                    break;
                }
            }
        }
        return flag;
    }
}
```